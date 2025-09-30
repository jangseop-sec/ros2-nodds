#include "symros/symros_graph.h"
#include <string.h>
#include <stdlib.h>

// ---------- 싱글턴 ----------
static symros_node_graph *g_graph = NULL;

static inline const char* safe(const char* s){ return s ? s : ""; }

// allocator helpers
static inline void* a_alloc(symros_node_graph* g, size_t n){ return g->alloc.allocate(n, g->alloc.state); }
static inline void* a_realloc(symros_node_graph* g, void* p, size_t n){ return g->alloc.reallocate(p, n, g->alloc.state); }
static inline void  a_free(symros_node_graph* g, void* p){ if(p) g->alloc.deallocate(p, g->alloc.state); }

// push/erase
static int ptr_push(symros_node_graph* g, void ***arr, size_t *cnt, void *p){
  void **tmp = (void**)a_realloc(g, *arr, (*cnt+1)*sizeof(void*));
  if(!tmp) return 0;
  tmp[*cnt] = p;
  *arr = tmp; (*cnt)++;
  return 1;
}
static int str_push(symros_node_graph* g, char ***arr, size_t *cnt, const char *s){
  char *dup = rcutils_strdup(safe(s), g->alloc);
  if(!dup) return 0;
  char **tmp = (char**)a_realloc(g, *arr, (*cnt+1)*sizeof(char*));
  if(!tmp){ a_free(g, dup); return 0; }
  tmp[*cnt] = dup;
  *arr = tmp; (*cnt)++;
  return 1;
}
static void str_array_free(symros_node_graph* g, char **arr, size_t cnt){
  if(!arr) return;
  for(size_t i=0;i<cnt;i++) a_free(g, arr[i]);
  a_free(g, arr);
}
static void erase_unordered_void(void **arr, size_t *cnt, size_t idx){
  if(idx>=*cnt) return;
  arr[idx] = arr[*cnt-1];
  (*cnt)--;
}

symros_node_graph * symros_get_node_graph(void){
  if(!g_graph){
    g_graph = (symros_node_graph*)calloc(1, sizeof(symros_node_graph));
    if(!g_graph) return NULL;
    g_graph->alloc = rcutils_get_default_allocator();
  }
  return g_graph;
}

// ---------- find/create ----------
static symros_node_info* find_node(symros_node_graph* g, rcl_node_t* node){
  for(size_t i=0;i<g->nodes_count;i++){
    if(g->nodes_info[i]->node == node) return g->nodes_info[i];
  }
  return NULL;
}
static symros_node_info* find_or_create_node(symros_node_graph* g, rcl_node_t* node){
  symros_node_info* info = find_node(g, node);
  if(info) return info;
  info = (symros_node_info*)a_alloc(g, sizeof(symros_node_info));
  if(!info) return NULL;
  memset(info, 0, sizeof(*info));
  info->node = node;
  if(!ptr_push(g, (void***)&g->nodes_info, &g->nodes_count, info)){
    a_free(g, info); return NULL;
  }
  return info;
}

// ---------- add ----------
void symros_add_node(rcl_node_t * node){
  if(!node) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  (void)find_or_create_node(g, node);
}
void symros_add_publisher(rcl_node_t * node, rcl_publisher_t * pub, const char * type_){
  if(!node || !pub) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  symros_node_info* n = find_or_create_node(g, node);
  if(n){ ptr_push(g, (void***)&n->pubs, &n->pubs_count, pub); str_push(g, &n->pubs_type, &n->pubs_type_count, type_); }
}
void symros_add_subscription(rcl_node_t * node, rcl_subscription_t * sub, const char * type_){
  if(!node || !sub) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  symros_node_info* n = find_or_create_node(g, node);
  if(n){ ptr_push(g, (void***)&n->subs, &n->subs_count, sub); str_push(g, &n->subs_type, &n->subs_type_count, type_); }
}
void symros_add_service(rcl_node_t * node, rcl_service_t * srv, const char * type_){
  if(!node || !srv) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  symros_node_info* n = find_or_create_node(g, node);
  if(n){ ptr_push(g, (void***)&n->srvs, &n->srvs_count, srv); str_push(g, &n->srvs_type, &n->srvs_type_count, type_); }
}
void symros_add_client(rcl_node_t * node, rcl_client_t * client, const char * type_){
  if(!node || !client) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  symros_node_info* n = find_or_create_node(g, node);
  if(n){ ptr_push(g, (void***)&n->clients, &n->clients_count, client); str_push(g, &n->clients_type, &n->clients_type_count, type_); }
}

// ---------- remove ----------
void symros_remove_node(rcl_node_t * node){
  if(!node) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  for(size_t i=0;i<g->nodes_count;i++){
    if(g->nodes_info[i]->node == node){
      symros_node_info *n = g->nodes_info[i];
      str_array_free(g, n->pubs_type, n->pubs_type_count);
      str_array_free(g, n->subs_type, n->subs_type_count);
      str_array_free(g, n->srvs_type, n->srvs_type_count);
      str_array_free(g, n->clients_type, n->clients_type_count);
      a_free(g, n->pubs); a_free(g, n->subs); a_free(g, n->srvs); a_free(g, n->clients);
      a_free(g, n);
      g->nodes_info[i] = g->nodes_info[g->nodes_count-1];
      g->nodes_count--;
      break;
    }
  }
}
void symros_remove_publisher(rcl_publisher_t * pub){
  if(!pub) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->pubs_count;i++){
      if(n->pubs[i]==pub){
        erase_unordered_void((void**)n->pubs, &n->pubs_count, i);
        if(i<n->pubs_type_count){ a_free(g, n->pubs_type[i]); erase_unordered_void((void**)n->pubs_type, &n->pubs_type_count, i); }
        return;
      }
    }
  }
}
void symros_remove_subscription(rcl_subscription_t * sub){
  if(!sub) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->subs_count;i++){
      if(n->subs[i]==sub){
        erase_unordered_void((void**)n->subs, &n->subs_count, i);
        if(i<n->subs_type_count){ a_free(g, n->subs_type[i]); erase_unordered_void((void**)n->subs_type, &n->subs_type_count, i); }
        return;
      }
    }
  }
}
void symros_remove_service(rcl_service_t * srv){
  if(!srv) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->srvs_count;i++){
      if(n->srvs[i]==srv){
        erase_unordered_void((void**)n->srvs, &n->srvs_count, i);
        if(i<n->srvs_type_count){ a_free(g, n->srvs_type[i]); erase_unordered_void((void**)n->srvs_type, &n->srvs_type_count, i); }
        return;
      }
    }
  }
}
void symros_remove_client(rcl_client_t * client){
  if(!client) return;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->clients_count;i++){
      if(n->clients[i]==client){
        erase_unordered_void((void**)n->clients, &n->clients_count, i);
        if(i<n->clients_type_count){ a_free(g, n->clients_type[i]); erase_unordered_void((void**)n->clients_type, &n->clients_type_count, i); }
        return;
      }
    }
  }
}

// ---------- node names ----------
rcl_ret_t symros_get_node_names(rcutils_string_array_t * node_names, rcutils_string_array_t * node_namespaces){
  if(!node_names || !node_namespaces) return RCL_RET_INVALID_ARGUMENT;
  rcutils_allocator_t a = rcutils_get_default_allocator();

  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;
  size_t n = g->nodes_count;

  *node_names = rcutils_get_zero_initialized_string_array();
  *node_namespaces = rcutils_get_zero_initialized_string_array();
  if(RCUTILS_RET_OK != rcutils_string_array_init(node_names, n, &a) ||
     RCUTILS_RET_OK != rcutils_string_array_init(node_namespaces, n, &a)){
    rcutils_string_array_fini(node_names);
    rcutils_string_array_fini(node_namespaces);
    return RCL_RET_BAD_ALLOC;
  }

  for(size_t i=0;i<n;i++){
    symros_node_info *ni = g->nodes_info[i];
    const char* name = rcl_node_get_name(ni->node);
    const char* ns   = rcl_node_get_namespace(ni->node);
    node_names->data[i]      = rcutils_strdup(safe(name), a);
    node_namespaces->data[i] = rcutils_strdup(safe(ns),   a);
    if(!node_names->data[i] || !node_namespaces->data[i]){
      rcutils_string_array_fini(node_names);
      rcutils_string_array_fini(node_namespaces);
      return RCL_RET_BAD_ALLOC;
    }
  }
  return RCL_RET_OK;
}

// ---------- names & types 공통 유틸 ----------
typedef struct { char *name; char *type; } pair_t;

static void free_pairs(symros_node_graph* g, pair_t* pairs, size_t cnt){
  if(!pairs) return;
  for(size_t i=0;i<cnt;i++){ a_free(g, pairs[i].name); a_free(g, pairs[i].type); }
  a_free(g, pairs);
}

static rcl_ret_t fill_rcl_names_and_types(symros_node_graph* g,
  char **names, char ***types, size_t *type_counts, size_t name_count,
  rcl_names_and_types_t *out)
{
  if(!out) return RCL_RET_INVALID_ARGUMENT;
  rcutils_allocator_t aa = g->alloc;
  *out = rcl_get_zero_initialized_names_and_types();
  rcl_ret_t ret = rcl_names_and_types_init(out, name_count, &aa);
  if(ret != RCL_RET_OK) return ret;

  for(size_t i=0;i<name_count;i++){
    out->names.data[i] = rcutils_strdup(names[i], aa);
    rcutils_string_array_t arr = rcutils_get_zero_initialized_string_array();
    if(RCUTILS_RET_OK != rcutils_string_array_init(&arr, type_counts[i], &aa)){
      rcl_names_and_types_fini(out);
      return RCL_RET_BAD_ALLOC;
    }
    for(size_t j=0;j<type_counts[i]; j++){
      arr.data[j] = rcutils_strdup(types[i][j], aa);
      if(!arr.data[j]){ rcl_names_and_types_fini(out); return RCL_RET_BAD_ALLOC; }
    }
    out->types[i] = arr;
  }
  return RCL_RET_OK;
}

static rcl_ret_t build_names_and_types_from_pairs(symros_node_graph* g, pair_t* pairs, size_t pair_cnt, rcl_names_and_types_t* out){
  // unique names
  char **names=NULL; size_t names_cnt=0;
  for(size_t i=0;i<pair_cnt;i++){
    size_t j=0; for(; j<names_cnt; j++) if(0==strcmp(names[j], pairs[i].name)) break;
    if(j==names_cnt){
      char **tmp = (char**)a_realloc(g, names, (names_cnt+1)*sizeof(char*));
      if(!tmp){ a_free(g, names); return RCL_RET_BAD_ALLOC; }
      names = tmp;
      names[names_cnt++] = rcutils_strdup(pairs[i].name, g->alloc);
      if(!names[names_cnt-1]){ for(size_t t=0;t<names_cnt-1;t++) a_free(g, names[t]); a_free(g, names); return RCL_RET_BAD_ALLOC; }
    }
  }
  // types per name
  char ***types = (char***)a_alloc(g, names_cnt*sizeof(char**));
  size_t *type_counts = (size_t*)a_alloc(g, names_cnt*sizeof(size_t));
  if((names_cnt && (!types || !type_counts))){ a_free(g, types); a_free(g, type_counts); for(size_t t=0;t<names_cnt;t++) a_free(g, names[t]); a_free(g, names); return RCL_RET_BAD_ALLOC; }
  for(size_t i=0;i<names_cnt;i++){ types[i]=NULL; type_counts[i]=0; }

  for(size_t i=0;i<pair_cnt;i++){
    size_t idx=0; for(; idx<names_cnt; idx++) if(0==strcmp(names[idx], pairs[i].name)) break;
    size_t t=0; for(; t<type_counts[idx]; t++) if(0==strcmp(types[idx][t], pairs[i].type)) break;
    if(t==type_counts[idx]){
      char **tmp = (char**)a_realloc(g, types[idx], (type_counts[idx]+1)*sizeof(char*));
      if(!tmp){ // cleanup
        for(size_t nn=0; nn<names_cnt; nn++){ for(size_t tt=0; tt<type_counts[nn]; tt++) a_free(g, types[nn][tt]); a_free(g, types[nn]); a_free(g, names[nn]); }
        a_free(g, types); a_free(g, type_counts); a_free(g, names);
        return RCL_RET_BAD_ALLOC;
      }
      types[idx] = tmp;
      types[idx][type_counts[idx]] = rcutils_strdup(pairs[i].type, g->alloc);
      if(!types[idx][type_counts[idx]]){ // cleanup
        for(size_t nn=0; nn<names_cnt; nn++){ for(size_t tt=0; tt<type_counts[nn]; tt++) a_free(g, types[nn][tt]); a_free(g, types[nn]); a_free(g, names[nn]); }
        a_free(g, types); a_free(g, type_counts); a_free(g, names);
        return RCL_RET_BAD_ALLOC;
      }
      type_counts[idx] += 1;
    }
  }

  rcl_ret_t r = fill_rcl_names_and_types(g, names, types, type_counts, names_cnt, out);

  // free temps
  for(size_t i=0;i<names_cnt;i++){
    a_free(g, names[i]);
    for(size_t t=0;t<type_counts[i]; t++) a_free(g, types[i][t]);
    a_free(g, types[i]);
  }
  a_free(g, names);
  a_free(g, types);
  a_free(g, type_counts);

  return r;
}

// pair collectors
static rcl_ret_t collect_topic_pairs(symros_node_graph* g, pair_t** out_pairs, size_t* out_cnt){
  pair_t *pairs=NULL; size_t pcnt=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->pubs_count;i++){
      const char* nm = rcl_publisher_get_topic_name(n->pubs[i]);
      const char* tp = (i<n->pubs_type_count)? n->pubs_type[i] : "";
      pair_t pr = { rcutils_strdup(safe(nm), g->alloc), rcutils_strdup(safe(tp), g->alloc) };
      pair_t *tmp = (pair_t*)a_realloc(g, pairs, (pcnt+1)*sizeof(pair_t));
      if(!tmp || !pr.name || !pr.type){ free_pairs(g, pairs, pcnt); if(pr.name) a_free(g, pr.name); if(pr.type) a_free(g, pr.type); return RCL_RET_BAD_ALLOC; }
      pairs = tmp; pairs[pcnt++] = pr;
    }
    for(size_t i=0;i<n->subs_count;i++){
      const char* nm = rcl_subscription_get_topic_name(n->subs[i]);
      const char* tp = (i<n->subs_type_count)? n->subs_type[i] : "";
      pair_t pr = { rcutils_strdup(safe(nm), g->alloc), rcutils_strdup(safe(tp), g->alloc) };
      pair_t *tmp = (pair_t*)a_realloc(g, pairs, (pcnt+1)*sizeof(pair_t));
      if(!tmp || !pr.name || !pr.type){ free_pairs(g, pairs, pcnt); if(pr.name) a_free(g, pr.name); if(pr.type) a_free(g, pr.type); return RCL_RET_BAD_ALLOC; }
      pairs = tmp; pairs[pcnt++] = pr;
    }
  }
  *out_pairs = pairs; *out_cnt = pcnt; return RCL_RET_OK;
}
static rcl_ret_t collect_service_pairs(symros_node_graph* g, pair_t** out_pairs, size_t* out_cnt){
  pair_t *pairs=NULL; size_t pcnt=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->srvs_count;i++){
      const char* nm = rcl_service_get_service_name(n->srvs[i]);
      const char* tp = (i<n->srvs_type_count)? n->srvs_type[i] : "";
      pair_t pr = { rcutils_strdup(safe(nm), g->alloc), rcutils_strdup(safe(tp), g->alloc) };
      pair_t *tmp = (pair_t*)a_realloc(g, pairs, (pcnt+1)*sizeof(pair_t));
      if(!tmp || !pr.name || !pr.type){ free_pairs(g, pairs, pcnt); if(pr.name) a_free(g, pr.name); if(pr.type) a_free(g, pr.type); return RCL_RET_BAD_ALLOC; }
      pairs = tmp; pairs[pcnt++] = pr;
    }
  }
  *out_pairs = pairs; *out_cnt = pcnt; return RCL_RET_OK;
}

// ---------- queries ----------
rcl_ret_t symros_get_publisher_names_and_types_by_node(char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types){
  if(!node_name || !topic_names_and_types) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  pair_t *pairs=NULL; size_t pcnt=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    const char* nn = rcl_node_get_name(n->node);
    const char* ns = rcl_node_get_namespace(n->node);
    if(strcmp(safe(nn), node_name)==0 && (!valid_namespace || strcmp(safe(ns), valid_namespace)==0)){
      for(size_t i=0;i<n->pubs_count;i++){
        const char* tname = rcl_publisher_get_topic_name(n->pubs[i]);
        const char* ttype = (i<n->pubs_type_count)? n->pubs_type[i] : "";
        pair_t pr = { rcutils_strdup(safe(tname), g->alloc), rcutils_strdup(safe(ttype), g->alloc) };
        pair_t *tmp = (pair_t*)a_realloc(g, pairs, (pcnt+1)*sizeof(pair_t));
        if(!tmp || !pr.name || !pr.type){ free_pairs(g, pairs, pcnt); if(pr.name) a_free(g, pr.name); if(pr.type) a_free(g, pr.type); return RCL_RET_BAD_ALLOC; }
        pairs = tmp; pairs[pcnt++] = pr;
      }
    }
  }
  rcl_ret_t r = build_names_and_types_from_pairs(g, pairs, pcnt, topic_names_and_types);
  free_pairs(g, pairs, pcnt);
  return r;
}
rcl_ret_t symros_get_subscriber_names_and_types_by_node(char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types){
  if(!node_name || !topic_names_and_types) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  pair_t *pairs=NULL; size_t pcnt=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    const char* nn = rcl_node_get_name(n->node);
    const char* ns = rcl_node_get_namespace(n->node);
    if(strcmp(safe(nn), node_name)==0 && (!valid_namespace || strcmp(safe(ns), valid_namespace)==0)){
      for(size_t i=0;i<n->subs_count;i++){
        const char* tname = rcl_subscription_get_topic_name(n->subs[i]);
        const char* ttype = (i<n->subs_type_count)? n->subs_type[i] : "";
        pair_t pr = { rcutils_strdup(safe(tname), g->alloc), rcutils_strdup(safe(ttype), g->alloc) };
        pair_t *tmp = (pair_t*)a_realloc(g, pairs, (pcnt+1)*sizeof(pair_t));
        if(!tmp || !pr.name || !pr.type){ free_pairs(g, pairs, pcnt); if(pr.name) a_free(g, pr.name); if(pr.type) a_free(g, pr.type); return RCL_RET_BAD_ALLOC; }
        pairs = tmp; pairs[pcnt++] = pr;
      }
    }
  }
  rcl_ret_t r = build_names_and_types_from_pairs(g, pairs, pcnt, topic_names_and_types);
  free_pairs(g, pairs, pcnt);
  return r;
}
rcl_ret_t symros_get_service_names_and_types_by_node(char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types){
  if(!node_name || !topic_names_and_types) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  pair_t *pairs=NULL; size_t pcnt=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    const char* nn = rcl_node_get_name(n->node);
    const char* ns = rcl_node_get_namespace(n->node);
    if(strcmp(safe(nn), node_name)==0 && (!valid_namespace || strcmp(safe(ns), valid_namespace)==0)){
      for(size_t i=0;i<n->srvs_count;i++){
        const char* sname = rcl_service_get_service_name(n->srvs[i]);
        const char* stype = (i<n->srvs_type_count)? n->srvs_type[i] : "";
        pair_t pr = { rcutils_strdup(safe(sname), g->alloc), rcutils_strdup(safe(stype), g->alloc) };
        pair_t *tmp = (pair_t*)a_realloc(g, pairs, (pcnt+1)*sizeof(pair_t));
        if(!tmp || !pr.name || !pr.type){ free_pairs(g, pairs, pcnt); if(pr.name) a_free(g, pr.name); if(pr.type) a_free(g, pr.type); return RCL_RET_BAD_ALLOC; }
        pairs = tmp; pairs[pcnt++] = pr;
      }
    }
  }
  rcl_ret_t r = build_names_and_types_from_pairs(g, pairs, pcnt, topic_names_and_types);
  free_pairs(g, pairs, pcnt);
  return r;
}
rcl_ret_t symros_get_client_names_and_types_by_node(char * node_name, char * valid_namespace, rcl_names_and_types_t * topic_names_and_types){
  // 클라이언트는 서비스 이름 기준으로 동일 취급
  return symros_get_service_names_and_types_by_node(node_name, valid_namespace, topic_names_and_types);
}

rcl_ret_t symros_get_topic_names_and_types_(rcl_names_and_types_t * topic_names_and_types){
  if(!topic_names_and_types) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  pair_t *pairs=NULL; size_t pcnt=0;
  rcl_ret_t cr = collect_topic_pairs(g, &pairs, &pcnt);
  if(cr != RCL_RET_OK) return cr;

  rcl_ret_t r = build_names_and_types_from_pairs(g, pairs, pcnt, topic_names_and_types);
  free_pairs(g, pairs, pcnt);
  return r;
}
rcl_ret_t symros_get_service_names_and_types(rcl_names_and_types_t * service_names_and_types){
  if(!service_names_and_types) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  pair_t *pairs=NULL; size_t pcnt=0;
  rcl_ret_t cr = collect_service_pairs(g, &pairs, &pcnt);
  if(cr != RCL_RET_OK) return cr;

  rcl_ret_t r = build_names_and_types_from_pairs(g, pairs, pcnt, service_names_and_types);
  free_pairs(g, pairs, pcnt);
  return r;
}

// ---------- counters & availability ----------
rcl_ret_t symros_count_publishers(const char * topic_name, size_t count /*unused*/){
  (void)count;
  if(!topic_name) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  size_t c=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->pubs_count;i++){
      if(0==strcmp(safe(rcl_publisher_get_topic_name(n->pubs[i])), topic_name)) c++;
    }
  }
  (void)c; // 원 시그니처가 값을 돌려줄 수 없으므로 내부 확인만
  return RCL_RET_OK;
}
rcl_ret_t symros_count_subscribers(const char * topic_name, size_t count /*unused*/){
  (void)count;
  if(!topic_name) return RCL_RET_INVALID_ARGUMENT;
  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;

  size_t c=0;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->subs_count;i++){
      if(0==strcmp(safe(rcl_subscription_get_topic_name(n->subs[i])), topic_name)) c++;
    }
  }
  (void)c;
  return RCL_RET_OK;
}

rcl_ret_t symros_service_server_is_available(const rcl_client_t * client, bool * is_available){
  if(!client || !is_available) return RCL_RET_INVALID_ARGUMENT;
  const char* svc = rcl_client_get_service_name(client);
  if(!svc){ *is_available=false; return RCL_RET_OK; }

  symros_node_graph* g = symros_get_node_graph(); if(!g) return RCL_RET_ERROR;
  for(size_t k=0;k<g->nodes_count;k++){
    symros_node_info *n = g->nodes_info[k];
    for(size_t i=0;i<n->srvs_count;i++){
      if(0==strcmp(safe(rcl_service_get_service_name(n->srvs[i])), svc)){
        *is_available = true; return RCL_RET_OK;
      }
    }
  }
  *is_available = false;
  return RCL_RET_OK;
}

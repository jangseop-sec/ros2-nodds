#include <iostream>
#include <vector>

#include "symros/symros.hpp"

namespace symros
{
  void 
  SymROSManager::init(bool is_target)
  {
    this->sub_idx = 0;
    this->srv_idx = 0;
    this->is_target = is_target;

    std::cout << "[symros_init] SymROSManager initialized" << std::endl;
  }

  void
  SymROSManager::add_subscription(std::shared_ptr<rclcpp::SubscriptionBase> sub_base)
  {
    if (sub_idx == -1) {
      throw std::runtime_error("SymROSManager not initialized");
    }
    sub_list.push_back(sub_base);
    sub_idx = sub_list.size()-1;
    
    if (is_target) {
      // TODO show result to python symros engine
      auto members = static_cast<const rosidl_typesupport_introspection_cpp::MessageMembers *>(sub_base->get_message_type_support_handle().data);
      std::string topic_namespace_ = members->message_namespace_;
      std::string topic_name_ = members->message_name_;

      std::string ret_prefix = "symros_result$$new_sub$$";
      std::string ret = ret_prefix + std::to_string(sub_idx) + "$$" + sub_base->get_topic_name() + "$$" + topic_namespace_ + "::" + topic_name_ + "\n";
      std::cout << ret;


      std::cout << "[symros_add_subscription] new subscription is created [" << sub_idx << "]" << members->message_namespace_ << "::" << members->message_name_ << std::endl;
    }
  }

  void
  SymROSManager::add_service(std::shared_ptr<rclcpp::ServiceBase> srv_base, std::string service_namespace_, std::string service_name_) {
    if (srv_idx == -1) {
      throw std::runtime_error("SymROSManager not initialized");
    }

    srv_list.push_back(srv_base);
    srv_idx = srv_list.size() - 1;

#ifndef SYMROS_MODE
    if (is_target) {
      std::string ret_prefix = "symros_result$$new_srv$$";
      std::string ret = ret_prefix + std::to_string(srv_idx) + "$$" + srv_base->get_service_name() + "$$" + service_namespace_ + "::" + service_name_  + "\n";
      std::cout << ret;
      std::cout << "[symros_add_service] new service is created [" << srv_idx << "]" << srv_base->get_service_name() << ":" << service_namespace_ << "::" << service_name_ << std::endl;
    }
#endif  // SYMROS_MODE
  }

  void
  SymROSManager::add_action(std::shared_ptr<rclcpp_action::ServerBase> action_server_base, std::string action_id_, std::string action_namespace_, std::string action_name_) {
    if (act_srv_idx == -1) {
      throw std::runtime_error("SymROSManager not initialized");
    }

    act_srv_list.push_back(action_server_base);
    act_srv_idx = act_srv_list.size() - 1;

  #ifndef SYMROS_MODE
    if (is_target) {
      std::string ret_prefix = "symros_result$$new_action_srv$$";
      std::string ret = ret_prefix + std::to_string(act_srv_idx) + "$$" + action_id_ + "$$" + action_namespace_ + "::" + action_name_  + "\n";
      std::cout << ret;
      std::cout << "[symros_add_action_server] new action server is created [" << act_srv_idx << "]" << action_id_ << ":" << action_namespace_ << "::" << action_name_ << std::endl;
    }
  #endif  // SYMROS_MODE
  }

  // void
  // SymROSManager::add_service(std::shared_ptr<rclcpp::ServiceBase> srv_base)
  // {
    
  //   if (srv_idx == -1) {
  //     throw std::runtime_error("SymROSManager not initialized");
  //   }

  //   srv_list.push_back(srv_base);

  //   if (is_target) {

  //     auto members = static_cast<const rosidl_typesupport_introspection_cpp::ServiceMembers *>(srv_base->get_service_handle()->)

  //     std::string ret_prefix = "symros_result$$new_srv$$";
  //     std::string ret = ret_prefix + std::to_string(srv_idx) + "$$" + srv_base->get_service_name() + "$$" +  + "\n";
  //     std::cout << ret;
  //     std::cout << "[symros_add_service] new service is created " << srv_base->get_service_name() << std::endl;
  //   }
  
  //   srv_idx++;
  // }

}


#ifndef SYMROS__SYMROS_HPP_
#define SYMROS__SYMROS_HPP_

#include <memory>
#include <vector>

#include "rclcpp/subscription.hpp"
#include "rclcpp/subscription_base.hpp"
#include "rclcpp/service.hpp"

#include "rclcpp_action/server.hpp"

#include "rcl/types.h"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"

namespace symros
{

class SymROSManager
{
public:
  static SymROSManager & get_instance()
  {
    static SymROSManager instance;
    return instance;
  }

  SymROSManager(const SymROSManager &) = delete;
  SymROSManager & operator=(const SymROSManager &) = delete;

  void 
  init(bool is_target);
  
  void
  add_subscription(std::shared_ptr<rclcpp::SubscriptionBase> sub_base);

  void
  add_service(std::shared_ptr<rclcpp::ServiceBase> srv_base, std::string service_namespace_, std::string service_name_);

  void
  add_action(std::shared_ptr<rclcpp_action::ServerBase> act_srv_base, std::string action_id_, std::string action_namespace_, std::string action_name_);
  

  template<typename T>
  typename rclcpp::Subscription<T>::SharedPtr
  get_subscription(int idx)
  {
    std::cout << "[symros_get_sub] get subscription" << std::endl;

    if (sub_idx == -1) {
      throw std::runtime_error("SymROSManager not initialized");
    }
    std::cout << sub_list.size() << std::endl;

    for (int i=0; i<sub_list.size(); ++i) {
      std::cout << "[symros] sub_idx[" << i << "] : " << sub_list[i]->get_topic_name() << std::endl;
    }


    if (idx < 0 || idx >= sub_list.size()) {
      std::cout << sub_list.size() << std::endl;
      throw std::out_of_range("Subscription index out of range");
    }

    std::cout << "[symros_get_sub] return subscription" << std::endl;
    
    using SubT = rclcpp::Subscription<T>;
    return std::static_pointer_cast<SubT>(sub_list[idx]);
  }

  template<typename serviceT>
  typename rclcpp::Service<serviceT>::SharedPtr
  get_service(int idx)
  {
    if (srv_idx == -1) {
      throw std::runtime_error("SymROSManager not initialized");
    }
    if (idx < 0 || idx >= srv_list.size()) {
      throw std::out_of_range("Service index out of range");
    }

    std::cout << "[symros] srv_idx[" << idx << "] : " << srv_list[idx]->get_service_name() << std::endl;
 
    
    return std::dynamic_pointer_cast<rclcpp::Service<serviceT>>(srv_list[idx]);
  }

private:
  SymROSManager() {}

  int sub_idx = -1;
  int srv_idx = -1;
  int act_srv_idx = -1;
  bool is_target;

  std::vector<std::shared_ptr<rclcpp::SubscriptionBase>> sub_list;
  std::vector<std::shared_ptr<rclcpp::ServiceBase>> srv_list;
  std::vector<std::shared_ptr<rclcpp_action::ServerBase>> act_srv_list;

};

}

#endif  // SYMROS__SYMROS_HPP_
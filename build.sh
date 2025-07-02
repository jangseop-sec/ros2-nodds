#!/bin/bash

INCLUDE_PATH="include"
BUILD_PATH="build"

# clean build folder
mkdir -p $BUILD_PATH && cd $BUILD_PATH && rm -rf *


c_pkgs=(
  rcl
  rcl/rcl
  rcl/rcl_lifecycle
  rcl/rcl_yaml_param_parser
  rcl_action
  rcl_logging_interfaces
  rcutils
  rmw
  rosidl
  rosidl/rosidl_runtime_c
  tracetools
)

cpp_pkgs=(
  ament_index_cpp
  rclcpp
  rclcpp/rclcpp
  rclcpp/rclcpp/contexts
  rclcpp/rclcpp/detail
  rclcpp/rclcpp/exceptions
  rclcpp/rclcpp/executors
  rclcpp/rclcpp/node_interfaces
  rclcpp/rclcpp/wait_set_policies
  rclcpp/rclcpp_actions
  rclcpp/rclcpp_lifecycle
  rclcpp/rclcpp_lifecycle/node_interfaces
  rcpputils
)

# c based packages compilation
echo "compile C based packages"
for pkg in "${c_pkgs[@]}"; do
  echo "compile $pkg package..."
  for src in ../src/$pkg/*.c; do
    filename="${src##*/}"
    obj="${pkg//\//__}__${filename%.c}.o"
    echo "compile $src => $obj ..."
    gcc -c -I ../$INCLUDE_PATH $src -o $obj
  done
done

# cpp based packages compilation
echo "compile C++ based pakcages"
for pkg in "${cpp_pkgs[@]}"; do
  echo "compile $pkg package..."
  for src in ../src/$pkg/*.cpp; do
    filename="${src##*/}"
    obj="${pkg//\//__}__${filename%.cpp}.o"
    echo "compile $src => $obj ..."
    g++ -c -I ../$INCLUDE_PATH $src -o $obj
  done
done

echo "generate static library"
ar rcs libros2_no_dds.a *.o
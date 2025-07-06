#!/bin/bash

INCLUDE_PATH="include"
BUILD_PATH="build"


# count file
file_list=$(find . -type f \( -name "*.c" -o -name "*.cpp" \))
count=$(echo "$file_list" | wc -l)
idx=1

# clean build folder
mkdir -p $BUILD_PATH && cd $BUILD_PATH 


msg_pkgs=(
  action_msgs/msg/detail
  action_msgs/srv/detail
  builtin_interfaces/msg/detail
  lifecycle_msgs/msg/detail
  lifecycle_msgs/srv/detail
  rcl_interfaces/msg/detail
  rcl_interfaces/srv/detail
  rosgraph_msgs/msg/detail
  statistics_msgs/msg/detail
  std_msgs/msg/detail
  unique_identifier_msgs/msg/detail
)

c_pkgs=(
  rcl/rcl
  rcl/rcl_lifecycle
  rcl/rcl_yaml_param_parser
  rcl_action
  rcl_logging_interface
  rcutils
  rmw
  rosidl/rosidl_runtime_c
  rosidl/rosidl_typesupport_introspection_c
  tracetools
)

cpp_pkgs=(
  ament_index_cpp
  rcpputils
  rcl_logging_interface
  rclcpp/rclcpp
  rclcpp/rclcpp/contexts
  rclcpp/rclcpp/detail
  rclcpp/rclcpp/exceptions
  rclcpp/rclcpp/executors
  rclcpp/rclcpp/node_interfaces
  rclcpp/rclcpp/wait_set_policies/detail
  rclcpp/rclcpp_action
  rclcpp/rclcpp_lifecycle
  rclcpp/rclcpp_lifecycle/node_interfaces
  libstatistics_collector/collector
  libstatistics_collector/moving_average_statistics
  rosidl/rosidl_typesupport_introspection_cpp
  tracetools
)

# c based packages compilation
echo "[+] compile C based packages"
for pkg in "${c_pkgs[@]}"; do
  for src in ../src/$pkg/*.c; do
    filename="${src##*/}"
    obj="${pkg//\//__}__${filename%.c}.o"
    if [ ! -f "$obj" ] || [ "$src" -nt "$obj" ]; then
      echo "[$idx/$count] compile $src => $obj ..."
      gcc -c -I ../$INCLUDE_PATH $src -o $obj
    else
      echo "[$idx/$count] $filename is up-do-date"
    fi
    idx=$((idx+1))
  done
done

# cpp based packages compilation
echo "[+] compile C++ based pakcages"
for pkg in "${cpp_pkgs[@]}"; do
  for src in ../src/$pkg/*.cpp; do
    filename="${src##*/}"
    obj="${pkg//\//__}__${filename%.cpp}.o"
    if [ ! -f "$obj" ] || [ "$src" -nt "$obj" ]; then
      echo "[$idx/$count] compile $src => $obj ..."
      g++ -c -I ../$INCLUDE_PATH $src -o $obj
    else
      echo "[$idx/$count] $filename is up-do-date"
    fi
    idx=$((idx+1))
  done
done

# msg packages compilation
echo "[+] compile message/service based packages"
for pkg in "${msg_pkgs[@]}"; do
  for src in ../include/$pkg/*.cpp; do
    filename="${src##*/}"
    obj="${pkg//\//__}__${filename%.cpp}_cpp.o"

    if [ ! -f "$obj" ] || [ "$src" -nt "$obj" ]; then
      echo "[$idx/$count] compile $src => $obj ..."
      g++ -c -I ../$INCLUDE_PATH $src -o $obj
    else
      echo "[$idx/$count] $filename is up-do-date"
    fi
    idx=$((idx+1))
  done
  for src in ../include/$pkg/*.c; do
    filename="${src##*/}"
    obj="${pkg//\//__}__${filename%.c}_c.o"
    if [ ! -f "$obj" ] || [ "$src" -nt "$obj" ]; then
      echo "[$idx/$count] compile $src => $obj ..."
      gcc -c -I ../$INCLUDE_PATH $src -o $obj
    else
      echo "[$idx/$count] $filename is up-do-date"
    fi
    idx=$((idx+1))
  done
done

echo "generate static library"
ar rcs libros2_no_dds.a *.o
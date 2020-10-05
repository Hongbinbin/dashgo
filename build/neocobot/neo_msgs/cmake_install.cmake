# Install script for directory: /home/eaibot/dashgo_ws/src/neocobot/neo_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/eaibot/dashgo_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/neo_msgs/msg" TYPE FILE FILES
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/msg/EndPose.msg"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/msg/JointAngles.msg"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/msg/JointVelocity.msg"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/msg/JointCurrent.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/neo_msgs/srv" TYPE FILE FILES
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Calibrate.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Forward.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/GetInput.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/GetMotorIds.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Hold.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Inverse.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/MoveToAngles.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/MoveToPose.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Recover.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Release.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Reset.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/SetEOATAction.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/SetOutput.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/Stop.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/MoveJ.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/MoveL.srv"
    "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/srv/MoveP.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/neo_msgs/cmake" TYPE FILE FILES "/home/eaibot/dashgo_ws/build/neocobot/neo_msgs/catkin_generated/installspace/neo_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/eaibot/dashgo_ws/devel/include/neo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/eaibot/dashgo_ws/devel/share/roseus/ros/neo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/eaibot/dashgo_ws/devel/share/common-lisp/ros/neo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/eaibot/dashgo_ws/devel/share/gennodejs/ros/neo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/eaibot/dashgo_ws/devel/lib/python2.7/dist-packages/neo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/eaibot/dashgo_ws/devel/lib/python2.7/dist-packages/neo_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/eaibot/dashgo_ws/build/neocobot/neo_msgs/catkin_generated/installspace/neo_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/neo_msgs/cmake" TYPE FILE FILES "/home/eaibot/dashgo_ws/build/neocobot/neo_msgs/catkin_generated/installspace/neo_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/neo_msgs/cmake" TYPE FILE FILES
    "/home/eaibot/dashgo_ws/build/neocobot/neo_msgs/catkin_generated/installspace/neo_msgsConfig.cmake"
    "/home/eaibot/dashgo_ws/build/neocobot/neo_msgs/catkin_generated/installspace/neo_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/neo_msgs" TYPE FILE FILES "/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/package.xml")
endif()


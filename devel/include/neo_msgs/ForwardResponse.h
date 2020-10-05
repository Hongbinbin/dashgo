// Generated by gencpp from file neo_msgs/ForwardResponse.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_FORWARDRESPONSE_H
#define NEO_MSGS_MESSAGE_FORWARDRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <neo_msgs/EndPose.h>

namespace neo_msgs
{
template <class ContainerAllocator>
struct ForwardResponse_
{
  typedef ForwardResponse_<ContainerAllocator> Type;

  ForwardResponse_()
    : event(0)
    , pose()  {
    }
  ForwardResponse_(const ContainerAllocator& _alloc)
    : event(0)
    , pose(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _event_type;
  _event_type event;

   typedef  ::neo_msgs::EndPose_<ContainerAllocator>  _pose_type;
  _pose_type pose;




  typedef boost::shared_ptr< ::neo_msgs::ForwardResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::neo_msgs::ForwardResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ForwardResponse_

typedef ::neo_msgs::ForwardResponse_<std::allocator<void> > ForwardResponse;

typedef boost::shared_ptr< ::neo_msgs::ForwardResponse > ForwardResponsePtr;
typedef boost::shared_ptr< ::neo_msgs::ForwardResponse const> ForwardResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::neo_msgs::ForwardResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::neo_msgs::ForwardResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace neo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'neo_msgs': ['/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::ForwardResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::ForwardResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::ForwardResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b3968c8b58fd1de7d2a4b79870505396";
  }

  static const char* value(const ::neo_msgs::ForwardResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb3968c8b58fd1de7ULL;
  static const uint64_t static_value2 = 0xd2a4b79870505396ULL;
};

template<class ContainerAllocator>
struct DataType< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "neo_msgs/ForwardResponse";
  }

  static const char* value(const ::neo_msgs::ForwardResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 event\n\
EndPose pose\n\
\n\
================================================================================\n\
MSG: neo_msgs/EndPose\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 Rx\n\
float64 Ry\n\
float64 Rz\n\
";
  }

  static const char* value(const ::neo_msgs::ForwardResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.event);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ForwardResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::neo_msgs::ForwardResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::neo_msgs::ForwardResponse_<ContainerAllocator>& v)
  {
    s << indent << "event: ";
    Printer<int32_t>::stream(s, indent + "  ", v.event);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::neo_msgs::EndPose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NEO_MSGS_MESSAGE_FORWARDRESPONSE_H

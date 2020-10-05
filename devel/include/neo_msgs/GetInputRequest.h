// Generated by gencpp from file neo_msgs/GetInputRequest.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_GETINPUTREQUEST_H
#define NEO_MSGS_MESSAGE_GETINPUTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace neo_msgs
{
template <class ContainerAllocator>
struct GetInputRequest_
{
  typedef GetInputRequest_<ContainerAllocator> Type;

  GetInputRequest_()
    : motor_ids()  {
    }
  GetInputRequest_(const ContainerAllocator& _alloc)
    : motor_ids(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _motor_ids_type;
  _motor_ids_type motor_ids;




  typedef boost::shared_ptr< ::neo_msgs::GetInputRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::neo_msgs::GetInputRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetInputRequest_

typedef ::neo_msgs::GetInputRequest_<std::allocator<void> > GetInputRequest;

typedef boost::shared_ptr< ::neo_msgs::GetInputRequest > GetInputRequestPtr;
typedef boost::shared_ptr< ::neo_msgs::GetInputRequest const> GetInputRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::neo_msgs::GetInputRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::neo_msgs::GetInputRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace neo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'neo_msgs': ['/home/eaibot/dashgo_ws/src/neocobot/neo_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::GetInputRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::GetInputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::GetInputRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bb0d6c2d9cfe8f7b5cba05d61857b47e";
  }

  static const char* value(const ::neo_msgs::GetInputRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbb0d6c2d9cfe8f7bULL;
  static const uint64_t static_value2 = 0x5cba05d61857b47eULL;
};

template<class ContainerAllocator>
struct DataType< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "neo_msgs/GetInputRequest";
  }

  static const char* value(const ::neo_msgs::GetInputRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32[] motor_ids\n\
";
  }

  static const char* value(const ::neo_msgs::GetInputRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.motor_ids);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetInputRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::neo_msgs::GetInputRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::neo_msgs::GetInputRequest_<ContainerAllocator>& v)
  {
    s << indent << "motor_ids[]" << std::endl;
    for (size_t i = 0; i < v.motor_ids.size(); ++i)
    {
      s << indent << "  motor_ids[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.motor_ids[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // NEO_MSGS_MESSAGE_GETINPUTREQUEST_H

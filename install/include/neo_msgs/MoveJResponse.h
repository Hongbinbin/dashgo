// Generated by gencpp from file neo_msgs/MoveJResponse.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_MOVEJRESPONSE_H
#define NEO_MSGS_MESSAGE_MOVEJRESPONSE_H


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
struct MoveJResponse_
{
  typedef MoveJResponse_<ContainerAllocator> Type;

  MoveJResponse_()
    : event(0)  {
    }
  MoveJResponse_(const ContainerAllocator& _alloc)
    : event(0)  {
  (void)_alloc;
    }



   typedef int32_t _event_type;
  _event_type event;




  typedef boost::shared_ptr< ::neo_msgs::MoveJResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::neo_msgs::MoveJResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MoveJResponse_

typedef ::neo_msgs::MoveJResponse_<std::allocator<void> > MoveJResponse;

typedef boost::shared_ptr< ::neo_msgs::MoveJResponse > MoveJResponsePtr;
typedef boost::shared_ptr< ::neo_msgs::MoveJResponse const> MoveJResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::neo_msgs::MoveJResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::neo_msgs::MoveJResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::MoveJResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::MoveJResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::MoveJResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b2a9c605bb7a420089b02c6063322298";
  }

  static const char* value(const ::neo_msgs::MoveJResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb2a9c605bb7a4200ULL;
  static const uint64_t static_value2 = 0x89b02c6063322298ULL;
};

template<class ContainerAllocator>
struct DataType< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "neo_msgs/MoveJResponse";
  }

  static const char* value(const ::neo_msgs::MoveJResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 event\n\
";
  }

  static const char* value(const ::neo_msgs::MoveJResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.event);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MoveJResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::neo_msgs::MoveJResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::neo_msgs::MoveJResponse_<ContainerAllocator>& v)
  {
    s << indent << "event: ";
    Printer<int32_t>::stream(s, indent + "  ", v.event);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NEO_MSGS_MESSAGE_MOVEJRESPONSE_H

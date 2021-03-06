// Generated by gencpp from file neo_msgs/GetMotorIdsResponse.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_GETMOTORIDSRESPONSE_H
#define NEO_MSGS_MESSAGE_GETMOTORIDSRESPONSE_H


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
struct GetMotorIdsResponse_
{
  typedef GetMotorIdsResponse_<ContainerAllocator> Type;

  GetMotorIdsResponse_()
    : event(0)
    , motor_ids()  {
    }
  GetMotorIdsResponse_(const ContainerAllocator& _alloc)
    : event(0)
    , motor_ids(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _event_type;
  _event_type event;

   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _motor_ids_type;
  _motor_ids_type motor_ids;




  typedef boost::shared_ptr< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetMotorIdsResponse_

typedef ::neo_msgs::GetMotorIdsResponse_<std::allocator<void> > GetMotorIdsResponse;

typedef boost::shared_ptr< ::neo_msgs::GetMotorIdsResponse > GetMotorIdsResponsePtr;
typedef boost::shared_ptr< ::neo_msgs::GetMotorIdsResponse const> GetMotorIdsResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "da45074f03ccd6c00fa83c029210839d";
  }

  static const char* value(const ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xda45074f03ccd6c0ULL;
  static const uint64_t static_value2 = 0x0fa83c029210839dULL;
};

template<class ContainerAllocator>
struct DataType< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "neo_msgs/GetMotorIdsResponse";
  }

  static const char* value(const ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 event\n\
int32[] motor_ids\n\
";
  }

  static const char* value(const ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.event);
      stream.next(m.motor_ids);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetMotorIdsResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::neo_msgs::GetMotorIdsResponse_<ContainerAllocator>& v)
  {
    s << indent << "event: ";
    Printer<int32_t>::stream(s, indent + "  ", v.event);
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

#endif // NEO_MSGS_MESSAGE_GETMOTORIDSRESPONSE_H

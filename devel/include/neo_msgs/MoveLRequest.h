// Generated by gencpp from file neo_msgs/MoveLRequest.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_MOVELREQUEST_H
#define NEO_MSGS_MESSAGE_MOVELREQUEST_H


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
struct MoveLRequest_
{
  typedef MoveLRequest_<ContainerAllocator> Type;

  MoveLRequest_()
    : points()
    , radius()
    , velocity(0.0)
    , acceleration(0.0)
    , interval(0.0)
    , close(false)  {
    }
  MoveLRequest_(const ContainerAllocator& _alloc)
    : points(_alloc)
    , radius(_alloc)
    , velocity(0.0)
    , acceleration(0.0)
    , interval(0.0)
    , close(false)  {
  (void)_alloc;
    }



   typedef std::vector< ::neo_msgs::EndPose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::neo_msgs::EndPose_<ContainerAllocator> >::other >  _points_type;
  _points_type points;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _radius_type;
  _radius_type radius;

   typedef float _velocity_type;
  _velocity_type velocity;

   typedef float _acceleration_type;
  _acceleration_type acceleration;

   typedef float _interval_type;
  _interval_type interval;

   typedef uint8_t _close_type;
  _close_type close;




  typedef boost::shared_ptr< ::neo_msgs::MoveLRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::neo_msgs::MoveLRequest_<ContainerAllocator> const> ConstPtr;

}; // struct MoveLRequest_

typedef ::neo_msgs::MoveLRequest_<std::allocator<void> > MoveLRequest;

typedef boost::shared_ptr< ::neo_msgs::MoveLRequest > MoveLRequestPtr;
typedef boost::shared_ptr< ::neo_msgs::MoveLRequest const> MoveLRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::neo_msgs::MoveLRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::neo_msgs::MoveLRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::neo_msgs::MoveLRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::neo_msgs::MoveLRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::neo_msgs::MoveLRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "883badead9a54a7744ba21e12a8efe73";
  }

  static const char* value(const ::neo_msgs::MoveLRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x883badead9a54a77ULL;
  static const uint64_t static_value2 = 0x44ba21e12a8efe73ULL;
};

template<class ContainerAllocator>
struct DataType< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "neo_msgs/MoveLRequest";
  }

  static const char* value(const ::neo_msgs::MoveLRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "EndPose[] points\n\
float64[] radius\n\
float32 velocity\n\
float32 acceleration\n\
float32 interval\n\
bool close\n\
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

  static const char* value(const ::neo_msgs::MoveLRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.points);
      stream.next(m.radius);
      stream.next(m.velocity);
      stream.next(m.acceleration);
      stream.next(m.interval);
      stream.next(m.close);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MoveLRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::neo_msgs::MoveLRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::neo_msgs::MoveLRequest_<ContainerAllocator>& v)
  {
    s << indent << "points[]" << std::endl;
    for (size_t i = 0; i < v.points.size(); ++i)
    {
      s << indent << "  points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::neo_msgs::EndPose_<ContainerAllocator> >::stream(s, indent + "    ", v.points[i]);
    }
    s << indent << "radius[]" << std::endl;
    for (size_t i = 0; i < v.radius.size(); ++i)
    {
      s << indent << "  radius[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.radius[i]);
    }
    s << indent << "velocity: ";
    Printer<float>::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.acceleration);
    s << indent << "interval: ";
    Printer<float>::stream(s, indent + "  ", v.interval);
    s << indent << "close: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.close);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NEO_MSGS_MESSAGE_MOVELREQUEST_H

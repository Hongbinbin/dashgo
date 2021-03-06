// Generated by gencpp from file neo_msgs/MoveToAngles.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_MOVETOANGLES_H
#define NEO_MSGS_MESSAGE_MOVETOANGLES_H

#include <ros/service_traits.h>


#include <neo_msgs/MoveToAnglesRequest.h>
#include <neo_msgs/MoveToAnglesResponse.h>


namespace neo_msgs
{

struct MoveToAngles
{

typedef MoveToAnglesRequest Request;
typedef MoveToAnglesResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveToAngles
} // namespace neo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::neo_msgs::MoveToAngles > {
  static const char* value()
  {
    return "df013f5f4546b148508f366c4f2a3858";
  }

  static const char* value(const ::neo_msgs::MoveToAngles&) { return value(); }
};

template<>
struct DataType< ::neo_msgs::MoveToAngles > {
  static const char* value()
  {
    return "neo_msgs/MoveToAngles";
  }

  static const char* value(const ::neo_msgs::MoveToAngles&) { return value(); }
};


// service_traits::MD5Sum< ::neo_msgs::MoveToAnglesRequest> should match 
// service_traits::MD5Sum< ::neo_msgs::MoveToAngles > 
template<>
struct MD5Sum< ::neo_msgs::MoveToAnglesRequest>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::MoveToAngles >::value();
  }
  static const char* value(const ::neo_msgs::MoveToAnglesRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::MoveToAnglesRequest> should match 
// service_traits::DataType< ::neo_msgs::MoveToAngles > 
template<>
struct DataType< ::neo_msgs::MoveToAnglesRequest>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::MoveToAngles >::value();
  }
  static const char* value(const ::neo_msgs::MoveToAnglesRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::neo_msgs::MoveToAnglesResponse> should match 
// service_traits::MD5Sum< ::neo_msgs::MoveToAngles > 
template<>
struct MD5Sum< ::neo_msgs::MoveToAnglesResponse>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::MoveToAngles >::value();
  }
  static const char* value(const ::neo_msgs::MoveToAnglesResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::MoveToAnglesResponse> should match 
// service_traits::DataType< ::neo_msgs::MoveToAngles > 
template<>
struct DataType< ::neo_msgs::MoveToAnglesResponse>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::MoveToAngles >::value();
  }
  static const char* value(const ::neo_msgs::MoveToAnglesResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NEO_MSGS_MESSAGE_MOVETOANGLES_H

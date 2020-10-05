// Generated by gencpp from file neo_msgs/MoveL.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_MOVEL_H
#define NEO_MSGS_MESSAGE_MOVEL_H

#include <ros/service_traits.h>


#include <neo_msgs/MoveLRequest.h>
#include <neo_msgs/MoveLResponse.h>


namespace neo_msgs
{

struct MoveL
{

typedef MoveLRequest Request;
typedef MoveLResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveL
} // namespace neo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::neo_msgs::MoveL > {
  static const char* value()
  {
    return "1bafbab7c9a1dae32abd70213e93073c";
  }

  static const char* value(const ::neo_msgs::MoveL&) { return value(); }
};

template<>
struct DataType< ::neo_msgs::MoveL > {
  static const char* value()
  {
    return "neo_msgs/MoveL";
  }

  static const char* value(const ::neo_msgs::MoveL&) { return value(); }
};


// service_traits::MD5Sum< ::neo_msgs::MoveLRequest> should match 
// service_traits::MD5Sum< ::neo_msgs::MoveL > 
template<>
struct MD5Sum< ::neo_msgs::MoveLRequest>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::MoveL >::value();
  }
  static const char* value(const ::neo_msgs::MoveLRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::MoveLRequest> should match 
// service_traits::DataType< ::neo_msgs::MoveL > 
template<>
struct DataType< ::neo_msgs::MoveLRequest>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::MoveL >::value();
  }
  static const char* value(const ::neo_msgs::MoveLRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::neo_msgs::MoveLResponse> should match 
// service_traits::MD5Sum< ::neo_msgs::MoveL > 
template<>
struct MD5Sum< ::neo_msgs::MoveLResponse>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::MoveL >::value();
  }
  static const char* value(const ::neo_msgs::MoveLResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::MoveLResponse> should match 
// service_traits::DataType< ::neo_msgs::MoveL > 
template<>
struct DataType< ::neo_msgs::MoveLResponse>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::MoveL >::value();
  }
  static const char* value(const ::neo_msgs::MoveLResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NEO_MSGS_MESSAGE_MOVEL_H

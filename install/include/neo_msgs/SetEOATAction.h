// Generated by gencpp from file neo_msgs/SetEOATAction.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_SETEOATACTION_H
#define NEO_MSGS_MESSAGE_SETEOATACTION_H

#include <ros/service_traits.h>


#include <neo_msgs/SetEOATActionRequest.h>
#include <neo_msgs/SetEOATActionResponse.h>


namespace neo_msgs
{

struct SetEOATAction
{

typedef SetEOATActionRequest Request;
typedef SetEOATActionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetEOATAction
} // namespace neo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::neo_msgs::SetEOATAction > {
  static const char* value()
  {
    return "f9a82cb332c3449f5a7f012529c9367e";
  }

  static const char* value(const ::neo_msgs::SetEOATAction&) { return value(); }
};

template<>
struct DataType< ::neo_msgs::SetEOATAction > {
  static const char* value()
  {
    return "neo_msgs/SetEOATAction";
  }

  static const char* value(const ::neo_msgs::SetEOATAction&) { return value(); }
};


// service_traits::MD5Sum< ::neo_msgs::SetEOATActionRequest> should match 
// service_traits::MD5Sum< ::neo_msgs::SetEOATAction > 
template<>
struct MD5Sum< ::neo_msgs::SetEOATActionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::SetEOATAction >::value();
  }
  static const char* value(const ::neo_msgs::SetEOATActionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::SetEOATActionRequest> should match 
// service_traits::DataType< ::neo_msgs::SetEOATAction > 
template<>
struct DataType< ::neo_msgs::SetEOATActionRequest>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::SetEOATAction >::value();
  }
  static const char* value(const ::neo_msgs::SetEOATActionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::neo_msgs::SetEOATActionResponse> should match 
// service_traits::MD5Sum< ::neo_msgs::SetEOATAction > 
template<>
struct MD5Sum< ::neo_msgs::SetEOATActionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::SetEOATAction >::value();
  }
  static const char* value(const ::neo_msgs::SetEOATActionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::SetEOATActionResponse> should match 
// service_traits::DataType< ::neo_msgs::SetEOATAction > 
template<>
struct DataType< ::neo_msgs::SetEOATActionResponse>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::SetEOATAction >::value();
  }
  static const char* value(const ::neo_msgs::SetEOATActionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NEO_MSGS_MESSAGE_SETEOATACTION_H

// Generated by gencpp from file neo_msgs/GetInput.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_GETINPUT_H
#define NEO_MSGS_MESSAGE_GETINPUT_H

#include <ros/service_traits.h>


#include <neo_msgs/GetInputRequest.h>
#include <neo_msgs/GetInputResponse.h>


namespace neo_msgs
{

struct GetInput
{

typedef GetInputRequest Request;
typedef GetInputResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetInput
} // namespace neo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::neo_msgs::GetInput > {
  static const char* value()
  {
    return "151f6f423f75ecb8922ac2bfb5b2965f";
  }

  static const char* value(const ::neo_msgs::GetInput&) { return value(); }
};

template<>
struct DataType< ::neo_msgs::GetInput > {
  static const char* value()
  {
    return "neo_msgs/GetInput";
  }

  static const char* value(const ::neo_msgs::GetInput&) { return value(); }
};


// service_traits::MD5Sum< ::neo_msgs::GetInputRequest> should match 
// service_traits::MD5Sum< ::neo_msgs::GetInput > 
template<>
struct MD5Sum< ::neo_msgs::GetInputRequest>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::GetInput >::value();
  }
  static const char* value(const ::neo_msgs::GetInputRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::GetInputRequest> should match 
// service_traits::DataType< ::neo_msgs::GetInput > 
template<>
struct DataType< ::neo_msgs::GetInputRequest>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::GetInput >::value();
  }
  static const char* value(const ::neo_msgs::GetInputRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::neo_msgs::GetInputResponse> should match 
// service_traits::MD5Sum< ::neo_msgs::GetInput > 
template<>
struct MD5Sum< ::neo_msgs::GetInputResponse>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::GetInput >::value();
  }
  static const char* value(const ::neo_msgs::GetInputResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::GetInputResponse> should match 
// service_traits::DataType< ::neo_msgs::GetInput > 
template<>
struct DataType< ::neo_msgs::GetInputResponse>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::GetInput >::value();
  }
  static const char* value(const ::neo_msgs::GetInputResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NEO_MSGS_MESSAGE_GETINPUT_H
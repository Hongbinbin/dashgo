// Generated by gencpp from file neo_msgs/SetOutput.msg
// DO NOT EDIT!


#ifndef NEO_MSGS_MESSAGE_SETOUTPUT_H
#define NEO_MSGS_MESSAGE_SETOUTPUT_H

#include <ros/service_traits.h>


#include <neo_msgs/SetOutputRequest.h>
#include <neo_msgs/SetOutputResponse.h>


namespace neo_msgs
{

struct SetOutput
{

typedef SetOutputRequest Request;
typedef SetOutputResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetOutput
} // namespace neo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::neo_msgs::SetOutput > {
  static const char* value()
  {
    return "1373bfb415f821cd86d00baf749212d2";
  }

  static const char* value(const ::neo_msgs::SetOutput&) { return value(); }
};

template<>
struct DataType< ::neo_msgs::SetOutput > {
  static const char* value()
  {
    return "neo_msgs/SetOutput";
  }

  static const char* value(const ::neo_msgs::SetOutput&) { return value(); }
};


// service_traits::MD5Sum< ::neo_msgs::SetOutputRequest> should match 
// service_traits::MD5Sum< ::neo_msgs::SetOutput > 
template<>
struct MD5Sum< ::neo_msgs::SetOutputRequest>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::SetOutput >::value();
  }
  static const char* value(const ::neo_msgs::SetOutputRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::SetOutputRequest> should match 
// service_traits::DataType< ::neo_msgs::SetOutput > 
template<>
struct DataType< ::neo_msgs::SetOutputRequest>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::SetOutput >::value();
  }
  static const char* value(const ::neo_msgs::SetOutputRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::neo_msgs::SetOutputResponse> should match 
// service_traits::MD5Sum< ::neo_msgs::SetOutput > 
template<>
struct MD5Sum< ::neo_msgs::SetOutputResponse>
{
  static const char* value()
  {
    return MD5Sum< ::neo_msgs::SetOutput >::value();
  }
  static const char* value(const ::neo_msgs::SetOutputResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::neo_msgs::SetOutputResponse> should match 
// service_traits::DataType< ::neo_msgs::SetOutput > 
template<>
struct DataType< ::neo_msgs::SetOutputResponse>
{
  static const char* value()
  {
    return DataType< ::neo_msgs::SetOutput >::value();
  }
  static const char* value(const ::neo_msgs::SetOutputResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // NEO_MSGS_MESSAGE_SETOUTPUT_H

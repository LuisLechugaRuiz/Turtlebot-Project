// Generated by gencpp from file turtlebot_2dnav/CarryingPerson.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_2DNAV_MESSAGE_CARRYINGPERSON_H
#define TURTLEBOT_2DNAV_MESSAGE_CARRYINGPERSON_H

#include <ros/service_traits.h>


#include <turtlebot_2dnav/CarryingPersonRequest.h>
#include <turtlebot_2dnav/CarryingPersonResponse.h>


namespace turtlebot_2dnav
{

struct CarryingPerson
{

typedef CarryingPersonRequest Request;
typedef CarryingPersonResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct CarryingPerson
} // namespace turtlebot_2dnav


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::turtlebot_2dnav::CarryingPerson > {
  static const char* value()
  {
    return "483ed3a7747788a7b78a207bdc605ba1";
  }

  static const char* value(const ::turtlebot_2dnav::CarryingPerson&) { return value(); }
};

template<>
struct DataType< ::turtlebot_2dnav::CarryingPerson > {
  static const char* value()
  {
    return "turtlebot_2dnav/CarryingPerson";
  }

  static const char* value(const ::turtlebot_2dnav::CarryingPerson&) { return value(); }
};


// service_traits::MD5Sum< ::turtlebot_2dnav::CarryingPersonRequest> should match
// service_traits::MD5Sum< ::turtlebot_2dnav::CarryingPerson >
template<>
struct MD5Sum< ::turtlebot_2dnav::CarryingPersonRequest>
{
  static const char* value()
  {
    return MD5Sum< ::turtlebot_2dnav::CarryingPerson >::value();
  }
  static const char* value(const ::turtlebot_2dnav::CarryingPersonRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlebot_2dnav::CarryingPersonRequest> should match
// service_traits::DataType< ::turtlebot_2dnav::CarryingPerson >
template<>
struct DataType< ::turtlebot_2dnav::CarryingPersonRequest>
{
  static const char* value()
  {
    return DataType< ::turtlebot_2dnav::CarryingPerson >::value();
  }
  static const char* value(const ::turtlebot_2dnav::CarryingPersonRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::turtlebot_2dnav::CarryingPersonResponse> should match
// service_traits::MD5Sum< ::turtlebot_2dnav::CarryingPerson >
template<>
struct MD5Sum< ::turtlebot_2dnav::CarryingPersonResponse>
{
  static const char* value()
  {
    return MD5Sum< ::turtlebot_2dnav::CarryingPerson >::value();
  }
  static const char* value(const ::turtlebot_2dnav::CarryingPersonResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlebot_2dnav::CarryingPersonResponse> should match
// service_traits::DataType< ::turtlebot_2dnav::CarryingPerson >
template<>
struct DataType< ::turtlebot_2dnav::CarryingPersonResponse>
{
  static const char* value()
  {
    return DataType< ::turtlebot_2dnav::CarryingPerson >::value();
  }
  static const char* value(const ::turtlebot_2dnav::CarryingPersonResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TURTLEBOT_2DNAV_MESSAGE_CARRYINGPERSON_H
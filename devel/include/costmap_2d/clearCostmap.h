// Generated by gencpp from file costmap_2d/clearCostmap.msg
// DO NOT EDIT!


#ifndef COSTMAP_2D_MESSAGE_CLEARCOSTMAP_H
#define COSTMAP_2D_MESSAGE_CLEARCOSTMAP_H

#include <ros/service_traits.h>


#include <costmap_2d/clearCostmapRequest.h>
#include <costmap_2d/clearCostmapResponse.h>


namespace costmap_2d
{

struct clearCostmap
{

typedef clearCostmapRequest Request;
typedef clearCostmapResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct clearCostmap
} // namespace costmap_2d


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::costmap_2d::clearCostmap > {
  static const char* value()
  {
    return "6f1cadb125ab62799a65523a8282332f";
  }

  static const char* value(const ::costmap_2d::clearCostmap&) { return value(); }
};

template<>
struct DataType< ::costmap_2d::clearCostmap > {
  static const char* value()
  {
    return "costmap_2d/clearCostmap";
  }

  static const char* value(const ::costmap_2d::clearCostmap&) { return value(); }
};


// service_traits::MD5Sum< ::costmap_2d::clearCostmapRequest> should match
// service_traits::MD5Sum< ::costmap_2d::clearCostmap >
template<>
struct MD5Sum< ::costmap_2d::clearCostmapRequest>
{
  static const char* value()
  {
    return MD5Sum< ::costmap_2d::clearCostmap >::value();
  }
  static const char* value(const ::costmap_2d::clearCostmapRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::costmap_2d::clearCostmapRequest> should match
// service_traits::DataType< ::costmap_2d::clearCostmap >
template<>
struct DataType< ::costmap_2d::clearCostmapRequest>
{
  static const char* value()
  {
    return DataType< ::costmap_2d::clearCostmap >::value();
  }
  static const char* value(const ::costmap_2d::clearCostmapRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::costmap_2d::clearCostmapResponse> should match
// service_traits::MD5Sum< ::costmap_2d::clearCostmap >
template<>
struct MD5Sum< ::costmap_2d::clearCostmapResponse>
{
  static const char* value()
  {
    return MD5Sum< ::costmap_2d::clearCostmap >::value();
  }
  static const char* value(const ::costmap_2d::clearCostmapResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::costmap_2d::clearCostmapResponse> should match
// service_traits::DataType< ::costmap_2d::clearCostmap >
template<>
struct DataType< ::costmap_2d::clearCostmapResponse>
{
  static const char* value()
  {
    return DataType< ::costmap_2d::clearCostmap >::value();
  }
  static const char* value(const ::costmap_2d::clearCostmapResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // COSTMAP_2D_MESSAGE_CLEARCOSTMAP_H

// Generated by gencpp from file costmap_2d/clearCostmapRequest.msg
// DO NOT EDIT!


#ifndef COSTMAP_2D_MESSAGE_CLEARCOSTMAPREQUEST_H
#define COSTMAP_2D_MESSAGE_CLEARCOSTMAPREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace costmap_2d
{
template <class ContainerAllocator>
struct clearCostmapRequest_
{
  typedef clearCostmapRequest_<ContainerAllocator> Type;

  clearCostmapRequest_()
    : clear(false)  {
    }
  clearCostmapRequest_(const ContainerAllocator& _alloc)
    : clear(false)  {
  (void)_alloc;
    }



   typedef uint8_t _clear_type;
  _clear_type clear;





  typedef boost::shared_ptr< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> const> ConstPtr;

}; // struct clearCostmapRequest_

typedef ::costmap_2d::clearCostmapRequest_<std::allocator<void> > clearCostmapRequest;

typedef boost::shared_ptr< ::costmap_2d::clearCostmapRequest > clearCostmapRequestPtr;
typedef boost::shared_ptr< ::costmap_2d::clearCostmapRequest const> clearCostmapRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::costmap_2d::clearCostmapRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::costmap_2d::clearCostmapRequest_<ContainerAllocator1> & lhs, const ::costmap_2d::clearCostmapRequest_<ContainerAllocator2> & rhs)
{
  return lhs.clear == rhs.clear;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::costmap_2d::clearCostmapRequest_<ContainerAllocator1> & lhs, const ::costmap_2d::clearCostmapRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace costmap_2d

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0f13874ec47789a29a9f87f75379435d";
  }

  static const char* value(const ::costmap_2d::clearCostmapRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0f13874ec47789a2ULL;
  static const uint64_t static_value2 = 0x9a9f87f75379435dULL;
};

template<class ContainerAllocator>
struct DataType< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "costmap_2d/clearCostmapRequest";
  }

  static const char* value(const ::costmap_2d::clearCostmapRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool clear\n"
;
  }

  static const char* value(const ::costmap_2d::clearCostmapRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.clear);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct clearCostmapRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::costmap_2d::clearCostmapRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::costmap_2d::clearCostmapRequest_<ContainerAllocator>& v)
  {
    s << indent << "clear: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.clear);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COSTMAP_2D_MESSAGE_CLEARCOSTMAPREQUEST_H
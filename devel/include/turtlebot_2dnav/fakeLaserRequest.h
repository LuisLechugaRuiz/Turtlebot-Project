// Generated by gencpp from file turtlebot_2dnav/fakeLaserRequest.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_2DNAV_MESSAGE_FAKELASERREQUEST_H
#define TURTLEBOT_2DNAV_MESSAGE_FAKELASERREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtlebot_2dnav
{
template <class ContainerAllocator>
struct fakeLaserRequest_
{
  typedef fakeLaserRequest_<ContainerAllocator> Type;

  fakeLaserRequest_()
    : active(false)  {
    }
  fakeLaserRequest_(const ContainerAllocator& _alloc)
    : active(false)  {
  (void)_alloc;
    }



   typedef uint8_t _active_type;
  _active_type active;





  typedef boost::shared_ptr< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> const> ConstPtr;

}; // struct fakeLaserRequest_

typedef ::turtlebot_2dnav::fakeLaserRequest_<std::allocator<void> > fakeLaserRequest;

typedef boost::shared_ptr< ::turtlebot_2dnav::fakeLaserRequest > fakeLaserRequestPtr;
typedef boost::shared_ptr< ::turtlebot_2dnav::fakeLaserRequest const> fakeLaserRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator1> & lhs, const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator2> & rhs)
{
  return lhs.active == rhs.active;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator1> & lhs, const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlebot_2dnav

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2c5cfb0a2565df41de6873994aee57d2";
  }

  static const char* value(const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2c5cfb0a2565df41ULL;
  static const uint64_t static_value2 = 0xde6873994aee57d2ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot_2dnav/fakeLaserRequest";
  }

  static const char* value(const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool active\n"
;
  }

  static const char* value(const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.active);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct fakeLaserRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot_2dnav::fakeLaserRequest_<ContainerAllocator>& v)
  {
    s << indent << "active: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.active);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_2DNAV_MESSAGE_FAKELASERREQUEST_H

// Generated by gencpp from file turtlebot_2dnav/askNewFrontierResponse.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_2DNAV_MESSAGE_ASKNEWFRONTIERRESPONSE_H
#define TURTLEBOT_2DNAV_MESSAGE_ASKNEWFRONTIERRESPONSE_H


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
struct askNewFrontierResponse_
{
  typedef askNewFrontierResponse_<ContainerAllocator> Type;

  askNewFrontierResponse_()
    : done(false)  {
    }
  askNewFrontierResponse_(const ContainerAllocator& _alloc)
    : done(false)  {
  (void)_alloc;
    }



   typedef uint8_t _done_type;
  _done_type done;





  typedef boost::shared_ptr< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> const> ConstPtr;

}; // struct askNewFrontierResponse_

typedef ::turtlebot_2dnav::askNewFrontierResponse_<std::allocator<void> > askNewFrontierResponse;

typedef boost::shared_ptr< ::turtlebot_2dnav::askNewFrontierResponse > askNewFrontierResponsePtr;
typedef boost::shared_ptr< ::turtlebot_2dnav::askNewFrontierResponse const> askNewFrontierResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator1> & lhs, const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator2> & rhs)
{
  return lhs.done == rhs.done;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator1> & lhs, const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlebot_2dnav

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "89bb254424e4cffedbf494e7b0ddbfea";
  }

  static const char* value(const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x89bb254424e4cffeULL;
  static const uint64_t static_value2 = 0xdbf494e7b0ddbfeaULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot_2dnav/askNewFrontierResponse";
  }

  static const char* value(const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool done\n"
"\n"
;
  }

  static const char* value(const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.done);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct askNewFrontierResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot_2dnav::askNewFrontierResponse_<ContainerAllocator>& v)
  {
    s << indent << "done: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.done);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_2DNAV_MESSAGE_ASKNEWFRONTIERRESPONSE_H

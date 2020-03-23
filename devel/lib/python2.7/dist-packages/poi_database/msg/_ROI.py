# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from poi_database/ROI.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import std_msgs.msg

class ROI(genpy.Message):
  _md5sum = "fe6aa07fdbecd8b2e91005f5ecf70714"
  _type = "poi_database/ROI"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """Header Header
string type
geometry_msgs/Point center
float32 size_x
float32 size_y
uint8 index
bool isnew

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
"""
  __slots__ = ['Header','type','center','size_x','size_y','index','isnew']
  _slot_types = ['std_msgs/Header','string','geometry_msgs/Point','float32','float32','uint8','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       Header,type,center,size_x,size_y,index,isnew

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ROI, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.Header is None:
        self.Header = std_msgs.msg.Header()
      if self.type is None:
        self.type = ''
      if self.center is None:
        self.center = geometry_msgs.msg.Point()
      if self.size_x is None:
        self.size_x = 0.
      if self.size_y is None:
        self.size_y = 0.
      if self.index is None:
        self.index = 0
      if self.isnew is None:
        self.isnew = False
    else:
      self.Header = std_msgs.msg.Header()
      self.type = ''
      self.center = geometry_msgs.msg.Point()
      self.size_x = 0.
      self.size_y = 0.
      self.index = 0
      self.isnew = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.Header.seq, _x.Header.stamp.secs, _x.Header.stamp.nsecs))
      _x = self.Header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.type
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3d2f2B().pack(_x.center.x, _x.center.y, _x.center.z, _x.size_x, _x.size_y, _x.index, _x.isnew))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.Header is None:
        self.Header = std_msgs.msg.Header()
      if self.center is None:
        self.center = geometry_msgs.msg.Point()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.Header.seq, _x.Header.stamp.secs, _x.Header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Header.frame_id = str[start:end].decode('utf-8')
      else:
        self.Header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.type = str[start:end].decode('utf-8')
      else:
        self.type = str[start:end]
      _x = self
      start = end
      end += 34
      (_x.center.x, _x.center.y, _x.center.z, _x.size_x, _x.size_y, _x.index, _x.isnew,) = _get_struct_3d2f2B().unpack(str[start:end])
      self.isnew = bool(self.isnew)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.Header.seq, _x.Header.stamp.secs, _x.Header.stamp.nsecs))
      _x = self.Header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.type
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3d2f2B().pack(_x.center.x, _x.center.y, _x.center.z, _x.size_x, _x.size_y, _x.index, _x.isnew))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.Header is None:
        self.Header = std_msgs.msg.Header()
      if self.center is None:
        self.center = geometry_msgs.msg.Point()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.Header.seq, _x.Header.stamp.secs, _x.Header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.Header.frame_id = str[start:end].decode('utf-8')
      else:
        self.Header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.type = str[start:end].decode('utf-8')
      else:
        self.type = str[start:end]
      _x = self
      start = end
      end += 34
      (_x.center.x, _x.center.y, _x.center.z, _x.size_x, _x.size_y, _x.index, _x.isnew,) = _get_struct_3d2f2B().unpack(str[start:end])
      self.isnew = bool(self.isnew)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_3d2f2B = None
def _get_struct_3d2f2B():
    global _struct_3d2f2B
    if _struct_3d2f2B is None:
        _struct_3d2f2B = struct.Struct("<3d2f2B")
    return _struct_3d2f2B

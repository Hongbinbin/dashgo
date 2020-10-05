# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from neo_msgs/MoveJRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import neo_msgs.msg

class MoveJRequest(genpy.Message):
  _md5sum = "d558b745fb37989689e245ec7c7b467c"
  _type = "neo_msgs/MoveJRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """EndPose[] points
float32 velocity
float32 acceleration
float32 interval
bool close

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
float64 Rz"""
  __slots__ = ['points','velocity','acceleration','interval','close']
  _slot_types = ['neo_msgs/EndPose[]','float32','float32','float32','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       points,velocity,acceleration,interval,close

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MoveJRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.points is None:
        self.points = []
      if self.velocity is None:
        self.velocity = 0.
      if self.acceleration is None:
        self.acceleration = 0.
      if self.interval is None:
        self.interval = 0.
      if self.close is None:
        self.close = False
    else:
      self.points = []
      self.velocity = 0.
      self.acceleration = 0.
      self.interval = 0.
      self.close = False

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
      length = len(self.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.points:
        _x = val1
        buff.write(_get_struct_6d().pack(_x.x, _x.y, _x.z, _x.Rx, _x.Ry, _x.Rz))
      _x = self
      buff.write(_get_struct_3fB().pack(_x.velocity, _x.acceleration, _x.interval, _x.close))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.points is None:
        self.points = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.points = []
      for i in range(0, length):
        val1 = neo_msgs.msg.EndPose()
        _x = val1
        start = end
        end += 48
        (_x.x, _x.y, _x.z, _x.Rx, _x.Ry, _x.Rz,) = _get_struct_6d().unpack(str[start:end])
        self.points.append(val1)
      _x = self
      start = end
      end += 13
      (_x.velocity, _x.acceleration, _x.interval, _x.close,) = _get_struct_3fB().unpack(str[start:end])
      self.close = bool(self.close)
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
      length = len(self.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.points:
        _x = val1
        buff.write(_get_struct_6d().pack(_x.x, _x.y, _x.z, _x.Rx, _x.Ry, _x.Rz))
      _x = self
      buff.write(_get_struct_3fB().pack(_x.velocity, _x.acceleration, _x.interval, _x.close))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.points is None:
        self.points = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.points = []
      for i in range(0, length):
        val1 = neo_msgs.msg.EndPose()
        _x = val1
        start = end
        end += 48
        (_x.x, _x.y, _x.z, _x.Rx, _x.Ry, _x.Rz,) = _get_struct_6d().unpack(str[start:end])
        self.points.append(val1)
      _x = self
      start = end
      end += 13
      (_x.velocity, _x.acceleration, _x.interval, _x.close,) = _get_struct_3fB().unpack(str[start:end])
      self.close = bool(self.close)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3fB = None
def _get_struct_3fB():
    global _struct_3fB
    if _struct_3fB is None:
        _struct_3fB = struct.Struct("<3fB")
    return _struct_3fB
_struct_6d = None
def _get_struct_6d():
    global _struct_6d
    if _struct_6d is None:
        _struct_6d = struct.Struct("<6d")
    return _struct_6d
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from neo_msgs/MoveJResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class MoveJResponse(genpy.Message):
  _md5sum = "b2a9c605bb7a420089b02c6063322298"
  _type = "neo_msgs/MoveJResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 event
"""
  __slots__ = ['event']
  _slot_types = ['int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       event

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MoveJResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.event is None:
        self.event = 0
    else:
      self.event = 0

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
      buff.write(_get_struct_i().pack(self.event))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (self.event,) = _get_struct_i().unpack(str[start:end])
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
      buff.write(_get_struct_i().pack(self.event))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (self.event,) = _get_struct_i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
class MoveJ(object):
  _type          = 'neo_msgs/MoveJ'
  _md5sum = 'c94ebec1f5e856eae9ca23929e46a5f8'
  _request_class  = MoveJRequest
  _response_class = MoveJResponse
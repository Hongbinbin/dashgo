# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from neo_msgs/MoveToPoseRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import neo_msgs.msg

class MoveToPoseRequest(genpy.Message):
  _md5sum = "9c345ad7293a476b4ba0628ca88f3694"
  _type = "neo_msgs/MoveToPoseRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """EndPose pose
float32 velocity
float32 acceleration
bool relative
bool block

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
float64 Rz"""
  __slots__ = ['pose','velocity','acceleration','relative','block']
  _slot_types = ['neo_msgs/EndPose','float32','float32','bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       pose,velocity,acceleration,relative,block

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MoveToPoseRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.pose is None:
        self.pose = neo_msgs.msg.EndPose()
      if self.velocity is None:
        self.velocity = 0.
      if self.acceleration is None:
        self.acceleration = 0.
      if self.relative is None:
        self.relative = False
      if self.block is None:
        self.block = False
    else:
      self.pose = neo_msgs.msg.EndPose()
      self.velocity = 0.
      self.acceleration = 0.
      self.relative = False
      self.block = False

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
      buff.write(_get_struct_6d2f2B().pack(_x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz, _x.velocity, _x.acceleration, _x.relative, _x.block))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.pose is None:
        self.pose = neo_msgs.msg.EndPose()
      end = 0
      _x = self
      start = end
      end += 58
      (_x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz, _x.velocity, _x.acceleration, _x.relative, _x.block,) = _get_struct_6d2f2B().unpack(str[start:end])
      self.relative = bool(self.relative)
      self.block = bool(self.block)
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
      buff.write(_get_struct_6d2f2B().pack(_x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz, _x.velocity, _x.acceleration, _x.relative, _x.block))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.pose is None:
        self.pose = neo_msgs.msg.EndPose()
      end = 0
      _x = self
      start = end
      end += 58
      (_x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz, _x.velocity, _x.acceleration, _x.relative, _x.block,) = _get_struct_6d2f2B().unpack(str[start:end])
      self.relative = bool(self.relative)
      self.block = bool(self.block)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6d2f2B = None
def _get_struct_6d2f2B():
    global _struct_6d2f2B
    if _struct_6d2f2B is None:
        _struct_6d2f2B = struct.Struct("<6d2f2B")
    return _struct_6d2f2B
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from neo_msgs/MoveToPoseResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class MoveToPoseResponse(genpy.Message):
  _md5sum = "b2a9c605bb7a420089b02c6063322298"
  _type = "neo_msgs/MoveToPoseResponse"
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
      super(MoveToPoseResponse, self).__init__(*args, **kwds)
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
class MoveToPose(object):
  _type          = 'neo_msgs/MoveToPose'
  _md5sum = '550b9435c70b6cfbf9422fec504e8a70'
  _request_class  = MoveToPoseRequest
  _response_class = MoveToPoseResponse

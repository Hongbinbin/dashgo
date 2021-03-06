# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from neo_msgs/ForwardRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ForwardRequest(genpy.Message):
  _md5sum = "b7ca77b9da2dfe623a276e10b570d2df"
  _type = "neo_msgs/ForwardRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64[] angles
"""
  __slots__ = ['angles']
  _slot_types = ['float64[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       angles

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ForwardRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.angles is None:
        self.angles = []
    else:
      self.angles = []

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
      length = len(self.angles)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.pack(pattern, *self.angles))
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
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.angles = struct.unpack(pattern, str[start:end])
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
      length = len(self.angles)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.angles.tostring())
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
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.angles = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from neo_msgs/ForwardResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import neo_msgs.msg

class ForwardResponse(genpy.Message):
  _md5sum = "b3968c8b58fd1de7d2a4b79870505396"
  _type = "neo_msgs/ForwardResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 event
EndPose pose

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
float64 Rz"""
  __slots__ = ['event','pose']
  _slot_types = ['int32','neo_msgs/EndPose']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       event,pose

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ForwardResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.event is None:
        self.event = 0
      if self.pose is None:
        self.pose = neo_msgs.msg.EndPose()
    else:
      self.event = 0
      self.pose = neo_msgs.msg.EndPose()

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
      buff.write(_get_struct_i6d().pack(_x.event, _x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz))
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
      end += 52
      (_x.event, _x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz,) = _get_struct_i6d().unpack(str[start:end])
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
      buff.write(_get_struct_i6d().pack(_x.event, _x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz))
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
      end += 52
      (_x.event, _x.pose.x, _x.pose.y, _x.pose.z, _x.pose.Rx, _x.pose.Ry, _x.pose.Rz,) = _get_struct_i6d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i6d = None
def _get_struct_i6d():
    global _struct_i6d
    if _struct_i6d is None:
        _struct_i6d = struct.Struct("<i6d")
    return _struct_i6d
class Forward(object):
  _type          = 'neo_msgs/Forward'
  _md5sum = '56fbdb4f932ad85907ae86d07f710cb2'
  _request_class  = ForwardRequest
  _response_class = ForwardResponse

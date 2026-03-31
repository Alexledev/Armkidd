# generated from rosidl_generator_py/resource/_idl.py.em
# with input from armkidd_interfaces:srv/MarkImg.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MarkImg_Request(type):
    """Metaclass of message 'MarkImg_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('armkidd_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'armkidd_interfaces.srv.MarkImg_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__mark_img__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__mark_img__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__mark_img__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__mark_img__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__mark_img__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarkImg_Request(metaclass=Metaclass_MarkImg_Request):
    """Message class 'MarkImg_Request'."""

    __slots__ = [
        '_x1',
        '_y1',
        '_x2',
        '_y2',
        '_choke_x',
        '_choke_y',
        '_is_valid',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'x1': 'int16',
        'y1': 'int16',
        'x2': 'int16',
        'y2': 'int16',
        'choke_x': 'int16',
        'choke_y': 'int16',
        'is_valid': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x1 = kwargs.get('x1', int())
        self.y1 = kwargs.get('y1', int())
        self.x2 = kwargs.get('x2', int())
        self.y2 = kwargs.get('y2', int())
        self.choke_x = kwargs.get('choke_x', int())
        self.choke_y = kwargs.get('choke_y', int())
        self.is_valid = kwargs.get('is_valid', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x1 != other.x1:
            return False
        if self.y1 != other.y1:
            return False
        if self.x2 != other.x2:
            return False
        if self.y2 != other.y2:
            return False
        if self.choke_x != other.choke_x:
            return False
        if self.choke_y != other.choke_y:
            return False
        if self.is_valid != other.is_valid:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x1(self):
        """Message field 'x1'."""
        return self._x1

    @x1.setter
    def x1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'x1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'x1' field must be an integer in [-32768, 32767]"
        self._x1 = value

    @builtins.property
    def y1(self):
        """Message field 'y1'."""
        return self._y1

    @y1.setter
    def y1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'y1' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'y1' field must be an integer in [-32768, 32767]"
        self._y1 = value

    @builtins.property
    def x2(self):
        """Message field 'x2'."""
        return self._x2

    @x2.setter
    def x2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'x2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'x2' field must be an integer in [-32768, 32767]"
        self._x2 = value

    @builtins.property
    def y2(self):
        """Message field 'y2'."""
        return self._y2

    @y2.setter
    def y2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'y2' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'y2' field must be an integer in [-32768, 32767]"
        self._y2 = value

    @builtins.property
    def choke_x(self):
        """Message field 'choke_x'."""
        return self._choke_x

    @choke_x.setter
    def choke_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'choke_x' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'choke_x' field must be an integer in [-32768, 32767]"
        self._choke_x = value

    @builtins.property
    def choke_y(self):
        """Message field 'choke_y'."""
        return self._choke_y

    @choke_y.setter
    def choke_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'choke_y' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'choke_y' field must be an integer in [-32768, 32767]"
        self._choke_y = value

    @builtins.property
    def is_valid(self):
        """Message field 'is_valid'."""
        return self._is_valid

    @is_valid.setter
    def is_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'is_valid' field must be of type 'bool'"
        self._is_valid = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MarkImg_Response(type):
    """Metaclass of message 'MarkImg_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('armkidd_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'armkidd_interfaces.srv.MarkImg_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__mark_img__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__mark_img__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__mark_img__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__mark_img__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__mark_img__response

            from std_msgs.msg import ByteMultiArray
            if ByteMultiArray.__class__._TYPE_SUPPORT is None:
                ByteMultiArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarkImg_Response(metaclass=Metaclass_MarkImg_Response):
    """Message class 'MarkImg_Response'."""

    __slots__ = [
        '_image',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'image': 'std_msgs/ByteMultiArray',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'ByteMultiArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import ByteMultiArray
        self.image = kwargs.get('image', ByteMultiArray())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.image != other.image:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def image(self):
        """Message field 'image'."""
        return self._image

    @image.setter
    def image(self, value):
        if self._check_fields:
            from std_msgs.msg import ByteMultiArray
            assert \
                isinstance(value, ByteMultiArray), \
                "The 'image' field must be a sub message of type 'ByteMultiArray'"
        self._image = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MarkImg_Event(type):
    """Metaclass of message 'MarkImg_Event'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('armkidd_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'armkidd_interfaces.srv.MarkImg_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__mark_img__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__mark_img__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__mark_img__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__mark_img__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__mark_img__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MarkImg_Event(metaclass=Metaclass_MarkImg_Event):
    """Message class 'MarkImg_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<armkidd_interfaces/MarkImg_Request, 1>',
        'response': 'sequence<armkidd_interfaces/MarkImg_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['armkidd_interfaces', 'srv'], 'MarkImg_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['armkidd_interfaces', 'srv'], 'MarkImg_Response'), 1),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from armkidd_interfaces.srv import MarkImg_Request
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, MarkImg_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'MarkImg_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from armkidd_interfaces.srv import MarkImg_Response
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, MarkImg_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'MarkImg_Response'"
        self._response = value


class Metaclass_MarkImg(type):
    """Metaclass of service 'MarkImg'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('armkidd_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'armkidd_interfaces.srv.MarkImg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__mark_img

            from armkidd_interfaces.srv import _mark_img
            if _mark_img.Metaclass_MarkImg_Request._TYPE_SUPPORT is None:
                _mark_img.Metaclass_MarkImg_Request.__import_type_support__()
            if _mark_img.Metaclass_MarkImg_Response._TYPE_SUPPORT is None:
                _mark_img.Metaclass_MarkImg_Response.__import_type_support__()
            if _mark_img.Metaclass_MarkImg_Event._TYPE_SUPPORT is None:
                _mark_img.Metaclass_MarkImg_Event.__import_type_support__()


class MarkImg(metaclass=Metaclass_MarkImg):
    from armkidd_interfaces.srv._mark_img import MarkImg_Request as Request
    from armkidd_interfaces.srv._mark_img import MarkImg_Response as Response
    from armkidd_interfaces.srv._mark_img import MarkImg_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')

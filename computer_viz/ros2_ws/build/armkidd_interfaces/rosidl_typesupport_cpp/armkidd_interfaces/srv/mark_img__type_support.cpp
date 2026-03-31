// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from armkidd_interfaces:srv/MarkImg.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "armkidd_interfaces/srv/detail/mark_img__functions.h"
#include "armkidd_interfaces/srv/detail/mark_img__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace armkidd_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MarkImg_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MarkImg_Request_type_support_ids_t;

static const _MarkImg_Request_type_support_ids_t _MarkImg_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MarkImg_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MarkImg_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MarkImg_Request_type_support_symbol_names_t _MarkImg_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armkidd_interfaces, srv, MarkImg_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, armkidd_interfaces, srv, MarkImg_Request)),
  }
};

typedef struct _MarkImg_Request_type_support_data_t
{
  void * data[2];
} _MarkImg_Request_type_support_data_t;

static _MarkImg_Request_type_support_data_t _MarkImg_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MarkImg_Request_message_typesupport_map = {
  2,
  "armkidd_interfaces",
  &_MarkImg_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MarkImg_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MarkImg_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MarkImg_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MarkImg_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &armkidd_interfaces__srv__MarkImg_Request__get_type_hash,
  &armkidd_interfaces__srv__MarkImg_Request__get_type_description,
  &armkidd_interfaces__srv__MarkImg_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Request>()
{
  return &::armkidd_interfaces::srv::rosidl_typesupport_cpp::MarkImg_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, armkidd_interfaces, srv, MarkImg_Request)() {
  return get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "armkidd_interfaces/srv/detail/mark_img__functions.h"
// already included above
// #include "armkidd_interfaces/srv/detail/mark_img__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace armkidd_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MarkImg_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MarkImg_Response_type_support_ids_t;

static const _MarkImg_Response_type_support_ids_t _MarkImg_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MarkImg_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MarkImg_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MarkImg_Response_type_support_symbol_names_t _MarkImg_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armkidd_interfaces, srv, MarkImg_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, armkidd_interfaces, srv, MarkImg_Response)),
  }
};

typedef struct _MarkImg_Response_type_support_data_t
{
  void * data[2];
} _MarkImg_Response_type_support_data_t;

static _MarkImg_Response_type_support_data_t _MarkImg_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MarkImg_Response_message_typesupport_map = {
  2,
  "armkidd_interfaces",
  &_MarkImg_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MarkImg_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MarkImg_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MarkImg_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MarkImg_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &armkidd_interfaces__srv__MarkImg_Response__get_type_hash,
  &armkidd_interfaces__srv__MarkImg_Response__get_type_description,
  &armkidd_interfaces__srv__MarkImg_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Response>()
{
  return &::armkidd_interfaces::srv::rosidl_typesupport_cpp::MarkImg_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, armkidd_interfaces, srv, MarkImg_Response)() {
  return get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "armkidd_interfaces/srv/detail/mark_img__functions.h"
// already included above
// #include "armkidd_interfaces/srv/detail/mark_img__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace armkidd_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MarkImg_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MarkImg_Event_type_support_ids_t;

static const _MarkImg_Event_type_support_ids_t _MarkImg_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MarkImg_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MarkImg_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MarkImg_Event_type_support_symbol_names_t _MarkImg_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armkidd_interfaces, srv, MarkImg_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, armkidd_interfaces, srv, MarkImg_Event)),
  }
};

typedef struct _MarkImg_Event_type_support_data_t
{
  void * data[2];
} _MarkImg_Event_type_support_data_t;

static _MarkImg_Event_type_support_data_t _MarkImg_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MarkImg_Event_message_typesupport_map = {
  2,
  "armkidd_interfaces",
  &_MarkImg_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MarkImg_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MarkImg_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MarkImg_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MarkImg_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &armkidd_interfaces__srv__MarkImg_Event__get_type_hash,
  &armkidd_interfaces__srv__MarkImg_Event__get_type_description,
  &armkidd_interfaces__srv__MarkImg_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Event>()
{
  return &::armkidd_interfaces::srv::rosidl_typesupport_cpp::MarkImg_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, armkidd_interfaces, srv, MarkImg_Event)() {
  return get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "armkidd_interfaces/srv/detail/mark_img__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace armkidd_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MarkImg_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MarkImg_type_support_ids_t;

static const _MarkImg_type_support_ids_t _MarkImg_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MarkImg_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MarkImg_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MarkImg_type_support_symbol_names_t _MarkImg_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armkidd_interfaces, srv, MarkImg)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, armkidd_interfaces, srv, MarkImg)),
  }
};

typedef struct _MarkImg_type_support_data_t
{
  void * data[2];
} _MarkImg_type_support_data_t;

static _MarkImg_type_support_data_t _MarkImg_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MarkImg_service_typesupport_map = {
  2,
  "armkidd_interfaces",
  &_MarkImg_service_typesupport_ids.typesupport_identifier[0],
  &_MarkImg_service_typesupport_symbol_names.symbol_name[0],
  &_MarkImg_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MarkImg_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MarkImg_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<armkidd_interfaces::srv::MarkImg_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<armkidd_interfaces::srv::MarkImg>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<armkidd_interfaces::srv::MarkImg>,
  &armkidd_interfaces__srv__MarkImg__get_type_hash,
  &armkidd_interfaces__srv__MarkImg__get_type_description,
  &armkidd_interfaces__srv__MarkImg__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace armkidd_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<armkidd_interfaces::srv::MarkImg>()
{
  return &::armkidd_interfaces::srv::rosidl_typesupport_cpp::MarkImg_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, armkidd_interfaces, srv, MarkImg)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<armkidd_interfaces::srv::MarkImg>();
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from actions_quiz_msg:action/Distance.idl
// generated code does not contain a copyright notice

#ifndef ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__TRAITS_HPP_
#define ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "actions_quiz_msg/action/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: seconds
  {
    out << "seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.seconds, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: seconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.seconds, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_Goal & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_Goal>()
{
  return "actions_quiz_msg::action::Distance_Goal";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_Goal>()
{
  return "actions_quiz_msg/action/Distance_Goal";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: total_dist
  {
    out << "total_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.total_dist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: total_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.total_dist, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_Result & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_Result>()
{
  return "actions_quiz_msg::action::Distance_Result";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_Result>()
{
  return "actions_quiz_msg/action/Distance_Result";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_dist
  {
    out << "current_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.current_dist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.current_dist, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_Feedback & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_Feedback>()
{
  return "actions_quiz_msg::action::Distance_Feedback";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_Feedback>()
{
  return "actions_quiz_msg/action/Distance_Feedback";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "actions_quiz_msg/action/detail/distance__traits.hpp"

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_SendGoal_Request & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_SendGoal_Request>()
{
  return "actions_quiz_msg::action::Distance_SendGoal_Request";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_SendGoal_Request>()
{
  return "actions_quiz_msg/action/Distance_SendGoal_Request";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<actions_quiz_msg::action::Distance_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<actions_quiz_msg::action::Distance_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_SendGoal_Response & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_SendGoal_Response>()
{
  return "actions_quiz_msg::action::Distance_SendGoal_Response";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_SendGoal_Response>()
{
  return "actions_quiz_msg/action/Distance_SendGoal_Response";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_SendGoal>()
{
  return "actions_quiz_msg::action::Distance_SendGoal";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_SendGoal>()
{
  return "actions_quiz_msg/action/Distance_SendGoal";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<actions_quiz_msg::action::Distance_SendGoal_Request>::value &&
    has_fixed_size<actions_quiz_msg::action::Distance_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<actions_quiz_msg::action::Distance_SendGoal_Request>::value &&
    has_bounded_size<actions_quiz_msg::action::Distance_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<actions_quiz_msg::action::Distance_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<actions_quiz_msg::action::Distance_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<actions_quiz_msg::action::Distance_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_GetResult_Request & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_GetResult_Request>()
{
  return "actions_quiz_msg::action::Distance_GetResult_Request";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_GetResult_Request>()
{
  return "actions_quiz_msg/action/Distance_GetResult_Request";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "actions_quiz_msg/action/detail/distance__traits.hpp"

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_GetResult_Response & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_GetResult_Response>()
{
  return "actions_quiz_msg::action::Distance_GetResult_Response";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_GetResult_Response>()
{
  return "actions_quiz_msg/action/Distance_GetResult_Response";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<actions_quiz_msg::action::Distance_Result>::value> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<actions_quiz_msg::action::Distance_Result>::value> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_GetResult>()
{
  return "actions_quiz_msg::action::Distance_GetResult";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_GetResult>()
{
  return "actions_quiz_msg/action/Distance_GetResult";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<actions_quiz_msg::action::Distance_GetResult_Request>::value &&
    has_fixed_size<actions_quiz_msg::action::Distance_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<actions_quiz_msg::action::Distance_GetResult_Request>::value &&
    has_bounded_size<actions_quiz_msg::action::Distance_GetResult_Response>::value
  >
{
};

template<>
struct is_service<actions_quiz_msg::action::Distance_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<actions_quiz_msg::action::Distance_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<actions_quiz_msg::action::Distance_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "actions_quiz_msg/action/detail/distance__traits.hpp"

namespace actions_quiz_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const Distance_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace actions_quiz_msg

namespace rosidl_generator_traits
{

[[deprecated("use actions_quiz_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const actions_quiz_msg::action::Distance_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  actions_quiz_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use actions_quiz_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const actions_quiz_msg::action::Distance_FeedbackMessage & msg)
{
  return actions_quiz_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<actions_quiz_msg::action::Distance_FeedbackMessage>()
{
  return "actions_quiz_msg::action::Distance_FeedbackMessage";
}

template<>
inline const char * name<actions_quiz_msg::action::Distance_FeedbackMessage>()
{
  return "actions_quiz_msg/action/Distance_FeedbackMessage";
}

template<>
struct has_fixed_size<actions_quiz_msg::action::Distance_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<actions_quiz_msg::action::Distance_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<actions_quiz_msg::action::Distance_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<actions_quiz_msg::action::Distance_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<actions_quiz_msg::action::Distance_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<actions_quiz_msg::action::Distance>
  : std::true_type
{
};

template<>
struct is_action_goal<actions_quiz_msg::action::Distance_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<actions_quiz_msg::action::Distance_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<actions_quiz_msg::action::Distance_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__TRAITS_HPP_

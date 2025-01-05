// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from actions_quiz_msg:action/Distance.idl
// generated code does not contain a copyright notice

#ifndef ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__BUILDER_HPP_
#define ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "actions_quiz_msg/action/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_Goal_seconds
{
public:
  Init_Distance_Goal_seconds()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::actions_quiz_msg::action::Distance_Goal seconds(::actions_quiz_msg::action::Distance_Goal::_seconds_type arg)
  {
    msg_.seconds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_Goal>()
{
  return actions_quiz_msg::action::builder::Init_Distance_Goal_seconds();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_Result_total_dist
{
public:
  explicit Init_Distance_Result_total_dist(::actions_quiz_msg::action::Distance_Result & msg)
  : msg_(msg)
  {}
  ::actions_quiz_msg::action::Distance_Result total_dist(::actions_quiz_msg::action::Distance_Result::_total_dist_type arg)
  {
    msg_.total_dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_Result msg_;
};

class Init_Distance_Result_status
{
public:
  Init_Distance_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distance_Result_total_dist status(::actions_quiz_msg::action::Distance_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Distance_Result_total_dist(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_Result>()
{
  return actions_quiz_msg::action::builder::Init_Distance_Result_status();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_Feedback_current_dist
{
public:
  Init_Distance_Feedback_current_dist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::actions_quiz_msg::action::Distance_Feedback current_dist(::actions_quiz_msg::action::Distance_Feedback::_current_dist_type arg)
  {
    msg_.current_dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_Feedback>()
{
  return actions_quiz_msg::action::builder::Init_Distance_Feedback_current_dist();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_SendGoal_Request_goal
{
public:
  explicit Init_Distance_SendGoal_Request_goal(::actions_quiz_msg::action::Distance_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::actions_quiz_msg::action::Distance_SendGoal_Request goal(::actions_quiz_msg::action::Distance_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_SendGoal_Request msg_;
};

class Init_Distance_SendGoal_Request_goal_id
{
public:
  Init_Distance_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distance_SendGoal_Request_goal goal_id(::actions_quiz_msg::action::Distance_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Distance_SendGoal_Request_goal(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_SendGoal_Request>()
{
  return actions_quiz_msg::action::builder::Init_Distance_SendGoal_Request_goal_id();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_SendGoal_Response_stamp
{
public:
  explicit Init_Distance_SendGoal_Response_stamp(::actions_quiz_msg::action::Distance_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::actions_quiz_msg::action::Distance_SendGoal_Response stamp(::actions_quiz_msg::action::Distance_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_SendGoal_Response msg_;
};

class Init_Distance_SendGoal_Response_accepted
{
public:
  Init_Distance_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distance_SendGoal_Response_stamp accepted(::actions_quiz_msg::action::Distance_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Distance_SendGoal_Response_stamp(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_SendGoal_Response>()
{
  return actions_quiz_msg::action::builder::Init_Distance_SendGoal_Response_accepted();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_GetResult_Request_goal_id
{
public:
  Init_Distance_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::actions_quiz_msg::action::Distance_GetResult_Request goal_id(::actions_quiz_msg::action::Distance_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_GetResult_Request>()
{
  return actions_quiz_msg::action::builder::Init_Distance_GetResult_Request_goal_id();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_GetResult_Response_result
{
public:
  explicit Init_Distance_GetResult_Response_result(::actions_quiz_msg::action::Distance_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::actions_quiz_msg::action::Distance_GetResult_Response result(::actions_quiz_msg::action::Distance_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_GetResult_Response msg_;
};

class Init_Distance_GetResult_Response_status
{
public:
  Init_Distance_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distance_GetResult_Response_result status(::actions_quiz_msg::action::Distance_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Distance_GetResult_Response_result(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_GetResult_Response>()
{
  return actions_quiz_msg::action::builder::Init_Distance_GetResult_Response_status();
}

}  // namespace actions_quiz_msg


namespace actions_quiz_msg
{

namespace action
{

namespace builder
{

class Init_Distance_FeedbackMessage_feedback
{
public:
  explicit Init_Distance_FeedbackMessage_feedback(::actions_quiz_msg::action::Distance_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::actions_quiz_msg::action::Distance_FeedbackMessage feedback(::actions_quiz_msg::action::Distance_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_FeedbackMessage msg_;
};

class Init_Distance_FeedbackMessage_goal_id
{
public:
  Init_Distance_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distance_FeedbackMessage_feedback goal_id(::actions_quiz_msg::action::Distance_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Distance_FeedbackMessage_feedback(msg_);
  }

private:
  ::actions_quiz_msg::action::Distance_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::actions_quiz_msg::action::Distance_FeedbackMessage>()
{
  return actions_quiz_msg::action::builder::Init_Distance_FeedbackMessage_goal_id();
}

}  // namespace actions_quiz_msg

#endif  // ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__BUILDER_HPP_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from actions_quiz_msg:action/Distance.idl
// generated code does not contain a copyright notice

#ifndef ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__STRUCT_H_
#define ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_Goal
{
  int32_t seconds;
} actions_quiz_msg__action__Distance_Goal;

// Struct for a sequence of actions_quiz_msg__action__Distance_Goal.
typedef struct actions_quiz_msg__action__Distance_Goal__Sequence
{
  actions_quiz_msg__action__Distance_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_Result
{
  bool status;
  double total_dist;
} actions_quiz_msg__action__Distance_Result;

// Struct for a sequence of actions_quiz_msg__action__Distance_Result.
typedef struct actions_quiz_msg__action__Distance_Result__Sequence
{
  actions_quiz_msg__action__Distance_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_Feedback
{
  double current_dist;
} actions_quiz_msg__action__Distance_Feedback;

// Struct for a sequence of actions_quiz_msg__action__Distance_Feedback.
typedef struct actions_quiz_msg__action__Distance_Feedback__Sequence
{
  actions_quiz_msg__action__Distance_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "actions_quiz_msg/action/detail/distance__struct.h"

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  actions_quiz_msg__action__Distance_Goal goal;
} actions_quiz_msg__action__Distance_SendGoal_Request;

// Struct for a sequence of actions_quiz_msg__action__Distance_SendGoal_Request.
typedef struct actions_quiz_msg__action__Distance_SendGoal_Request__Sequence
{
  actions_quiz_msg__action__Distance_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} actions_quiz_msg__action__Distance_SendGoal_Response;

// Struct for a sequence of actions_quiz_msg__action__Distance_SendGoal_Response.
typedef struct actions_quiz_msg__action__Distance_SendGoal_Response__Sequence
{
  actions_quiz_msg__action__Distance_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} actions_quiz_msg__action__Distance_GetResult_Request;

// Struct for a sequence of actions_quiz_msg__action__Distance_GetResult_Request.
typedef struct actions_quiz_msg__action__Distance_GetResult_Request__Sequence
{
  actions_quiz_msg__action__Distance_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "actions_quiz_msg/action/detail/distance__struct.h"

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_GetResult_Response
{
  int8_t status;
  actions_quiz_msg__action__Distance_Result result;
} actions_quiz_msg__action__Distance_GetResult_Response;

// Struct for a sequence of actions_quiz_msg__action__Distance_GetResult_Response.
typedef struct actions_quiz_msg__action__Distance_GetResult_Response__Sequence
{
  actions_quiz_msg__action__Distance_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "actions_quiz_msg/action/detail/distance__struct.h"

/// Struct defined in action/Distance in the package actions_quiz_msg.
typedef struct actions_quiz_msg__action__Distance_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  actions_quiz_msg__action__Distance_Feedback feedback;
} actions_quiz_msg__action__Distance_FeedbackMessage;

// Struct for a sequence of actions_quiz_msg__action__Distance_FeedbackMessage.
typedef struct actions_quiz_msg__action__Distance_FeedbackMessage__Sequence
{
  actions_quiz_msg__action__Distance_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} actions_quiz_msg__action__Distance_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTIONS_QUIZ_MSG__ACTION__DETAIL__DISTANCE__STRUCT_H_

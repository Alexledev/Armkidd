#ifndef TRANSMITMODAL
#define TRANSMITMODAL

#include <rclcpp/rclcpp.hpp>

enum TransmitStates : uint8_t
{
    Awaken = 11,
    AwakenComplete = 12,

    Rest = 13,
    RestComplete = 14,

    ArmMoving = 15,
    ArmMovingComplete = 16,

    GripperOpen = 21,
    GripperOpenComplete= 22,

    GripperClose = 23,
    GripperCloseComplete = 24,

    GripperGrasp = 25,
    GripperGraspComplete = 26
};

#endif
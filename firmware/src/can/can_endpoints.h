/*
* This file was automatically generated using Avlos.
* https://github.com/tinymovr/avlos
*
* Any changes to this file will be overwritten when
* content is regenerated.
*/

#pragma once
#include <src/common.h>

typedef enum
{
    AVLOS_RET_NOACTION,
    AVLOS_RET_READ = 1,
    AVLOS_RET_WRITE = 2,
    AVLOS_RET_CALL = 3
} Avlos_Return;

typedef enum
{
    AVLOS_CMD_WRITE,
    AVLOS_CMD_READ = 1
} Avlos_Command;

typedef enum
{
    ERRORS_NONE = 0,
    ERRORS_UNDERVOLTAGE = (1 << 0), 
    ERRORS_DRIVER_FAULT = (1 << 1), 
    ERRORS_CHARGE_PUMP_FAULT_STAT = (1 << 2), 
    ERRORS_CHARGE_PUMP_FAULT = (1 << 3), 
    ERRORS_DRV10_DISABLE = (1 << 4), 
    ERRORS_DRV32_DISABLE = (1 << 5), 
    ERRORS_DRV54_DISABLE = (1 << 6)
} errors_flags;

typedef enum
{
    SCHEDULER_ERRORS_NONE = 0,
    SCHEDULER_ERRORS_CONTROL_BLOCK_REENTERED = (1 << 0)
} scheduler_errors_flags;

typedef enum
{
    CONTROLLER_WARNINGS_NONE = 0,
    CONTROLLER_WARNINGS_VELOCITY_LIMITED = (1 << 0), 
    CONTROLLER_WARNINGS_CURRENT_LIMITED = (1 << 1), 
    CONTROLLER_WARNINGS_MODULATION_LIMITED = (1 << 2)
} controller_warnings_flags;

typedef enum
{
    CONTROLLER_ERRORS_NONE = 0,
    CONTROLLER_ERRORS_CURRENT_LIMIT_EXCEEDED = (1 << 0)
} controller_errors_flags;

typedef enum
{
    MOTOR_ERRORS_NONE = 0,
    MOTOR_ERRORS_PHASE_RESISTANCE_OUT_OF_RANGE = (1 << 0), 
    MOTOR_ERRORS_PHASE_INDUCTANCE_OUT_OF_RANGE = (1 << 1), 
    MOTOR_ERRORS_INVALID_POLE_PAIRS = (1 << 2)
} motor_errors_flags;

typedef enum
{
    SENSORS_SETUP_ONBOARD_ERRORS_NONE = 0,
    SENSORS_SETUP_ONBOARD_ERRORS_CALIBRATION_FAILED = (1 << 0), 
    SENSORS_SETUP_ONBOARD_ERRORS_READING_UNSTABLE = (1 << 1)
} sensors_setup_onboard_errors_flags;

typedef enum
{
    SENSORS_SETUP_EXTERNAL_SPI_ERRORS_NONE = 0,
    SENSORS_SETUP_EXTERNAL_SPI_ERRORS_CALIBRATION_FAILED = (1 << 0), 
    SENSORS_SETUP_EXTERNAL_SPI_ERRORS_READING_UNSTABLE = (1 << 1)
} sensors_setup_external_spi_errors_flags;

typedef enum
{
    SENSORS_SETUP_HALL_ERRORS_NONE = 0,
    SENSORS_SETUP_HALL_ERRORS_CALIBRATION_FAILED = (1 << 0), 
    SENSORS_SETUP_HALL_ERRORS_READING_UNSTABLE = (1 << 1)
} sensors_setup_hall_errors_flags;

typedef enum
{
    TRAJ_PLANNER_ERRORS_NONE = 0,
    TRAJ_PLANNER_ERRORS_INVALID_INPUT = (1 << 0), 
    TRAJ_PLANNER_ERRORS_VCRUISE_OVER_LIMIT = (1 << 1)
} traj_planner_errors_flags;

typedef enum
{
    HOMING_WARNINGS_NONE = 0,
    HOMING_WARNINGS_HOMING_TIMEOUT = (1 << 0)
} homing_warnings_flags;

typedef enum
{
    MOTOR_TYPE_HIGH_CURRENT = 0, 
    MOTOR_TYPE_GIMBAL = 1
} motor_type_options;

typedef enum
{
    SENSORS_SETUP_EXTERNAL_SPI_TYPE_MA7XX = 0, 
    SENSORS_SETUP_EXTERNAL_SPI_TYPE_AS5047 = 1, 
    SENSORS_SETUP_EXTERNAL_SPI_TYPE_AMT22 = 2
} sensors_setup_external_spi_type_options;

typedef enum
{
    SENSORS_SELECT_POSITION_TYPE_ONBOARD = 0, 
    SENSORS_SELECT_POSITION_TYPE_EXTERNAL_SPI = 1, 
    SENSORS_SELECT_POSITION_TYPE_HALL = 2
} sensors_select_position_type_options;

typedef enum
{
    SENSORS_SELECT_COMMUTATION_TYPE_ONBOARD = 0, 
    SENSORS_SELECT_COMMUTATION_TYPE_EXTERNAL_SPI = 1, 
    SENSORS_SELECT_COMMUTATION_TYPE_HALL = 2
} sensors_select_commutation_type_options;

extern uint32_t avlos_proto_hash;
extern uint8_t (*avlos_endpoints[88])(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);
extern uint32_t _avlos_get_proto_hash(void);

/*
* avlos_protocol_hash
*
* The Avlos protocol hash.
*
* Endpoint ID: 0
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_protocol_hash(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_uid
*
* The unique device ID, unique to each PAC55xx chip produced.
*
* Endpoint ID: 1
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_uid(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_fw_version
*
* The firmware version.
*
* Endpoint ID: 2
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_fw_version(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_hw_revision
*
* The hardware revision.
*
* Endpoint ID: 3
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_hw_revision(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_Vbus
*
* The measured bus voltage.
*
* Endpoint ID: 4
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_Vbus(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_Ibus
*
* The estimated bus current. Only estimates current drawn by motor.
*
* Endpoint ID: 5
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_Ibus(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_power
*
* The estimated power. Only estimates power drawn by motor.
*
* Endpoint ID: 6
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_power(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_temp
*
* The internal temperature of the PAC55xx MCU.
*
* Endpoint ID: 7
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_temp(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_calibrated
*
* Whether the system has been calibrated.
*
* Endpoint ID: 8
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_calibrated(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_errors
*
* Any system errors, as a bitmask
*
* Endpoint ID: 9
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_save_config
*
* Save configuration to non-volatile memory.
*
* Endpoint ID: 10
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_save_config(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_erase_config
*
* Erase the config stored in non-volatile memory and reset the device.
*
* Endpoint ID: 11
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_erase_config(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_reset
*
* Reset the device.
*
* Endpoint ID: 12
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_reset(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_enter_dfu
*
* Enter DFU mode.
*
* Endpoint ID: 13
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_enter_dfu(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_scheduler_errors
*
* Any scheduler errors, as a bitmask
*
* Endpoint ID: 14
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_scheduler_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_state
*
* The state of the controller.
*
* Endpoint ID: 15
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_state(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_mode
*
* The control mode of the controller.
*
* Endpoint ID: 16
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_mode(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_warnings
*
* Any controller warnings, as a bitmask
*
* Endpoint ID: 17
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_warnings(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_errors
*
* Any controller errors, as a bitmask
*
* Endpoint ID: 18
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_position_setpoint
*
* The position setpoint.
*
* Endpoint ID: 19
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_position_setpoint(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_position_p_gain
*
* The proportional gain of the position controller.
*
* Endpoint ID: 20
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_position_p_gain(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_setpoint
*
* The velocity setpoint.
*
* Endpoint ID: 21
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_setpoint(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_limit
*
* The velocity limit.
*
* Endpoint ID: 22
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_limit(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_p_gain
*
* The proportional gain of the velocity controller.
*
* Endpoint ID: 23
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_p_gain(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_i_gain
*
* The integral gain of the velocity controller.
*
* Endpoint ID: 24
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_i_gain(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_deadband
*
* The deadband of the velocity integrator. A region around the position setpoint where the velocity integrator is not updated.
*
* Endpoint ID: 25
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_deadband(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_increment
*
* Max velocity setpoint increment (ramping) rate. Set to 0 to disable.
*
* Endpoint ID: 26
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_increment(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_Iq_setpoint
*
* The Iq setpoint.
*
* Endpoint ID: 27
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_Iq_setpoint(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_Id_setpoint
*
* The Id setpoint.
*
* Endpoint ID: 28
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_Id_setpoint(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_Iq_limit
*
* The Iq limit.
*
* Endpoint ID: 29
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_Iq_limit(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_Iq_estimate
*
* The Iq estimate.
*
* Endpoint ID: 30
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_Iq_estimate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_bandwidth
*
* The current controller bandwidth.
*
* Endpoint ID: 31
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_bandwidth(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_Iq_p_gain
*
* The current controller proportional gain.
*
* Endpoint ID: 32
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_Iq_p_gain(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_max_Ibus_regen
*
* The max current allowed to be fed back to the power source before flux braking activates.
*
* Endpoint ID: 33
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_max_Ibus_regen(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_max_Ibrake
*
* The max current allowed to be dumped to the motor windings during flux braking. Set to zero to deactivate flux braking.
*
* Endpoint ID: 34
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_max_Ibrake(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_voltage_Vq_setpoint
*
* The Vq setpoint.
*
* Endpoint ID: 35
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_voltage_Vq_setpoint(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_calibrate
*
* Calibrate the device.
*
* Endpoint ID: 36
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_calibrate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_idle
*
* Set idle mode, disabling the driver.
*
* Endpoint ID: 37
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_idle(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_position_mode
*
* Set position control mode.
*
* Endpoint ID: 38
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_position_mode(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_velocity_mode
*
* Set velocity control mode.
*
* Endpoint ID: 39
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_velocity_mode(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_current_mode
*
* Set current control mode.
*
* Endpoint ID: 40
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_current_mode(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_controller_set_pos_vel_setpoints
*
* Set the position and velocity setpoints in one go, and retrieve the position estimate
*
* Endpoint ID: 41
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_controller_set_pos_vel_setpoints(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_comms_can_rate
*
* The baud rate of the CAN interface.
*
* Endpoint ID: 42
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_comms_can_rate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_comms_can_id
*
* The ID of the CAN interface.
*
* Endpoint ID: 43
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_comms_can_id(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_R
*
* The motor Resistance value.
*
* Endpoint ID: 44
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_R(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_L
*
* The motor Inductance value.
*
* Endpoint ID: 45
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_L(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_pole_pairs
*
* The motor pole pair count.
*
* Endpoint ID: 46
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_pole_pairs(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_type
*
* The type of the motor. Either high current or gimbal.
*
* Endpoint ID: 47
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_type(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_offset
*
* User-defined offset of the motor.
*
* Endpoint ID: 48
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_offset(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_direction
*
* User-defined direction of the motor.
*
* Endpoint ID: 49
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_direction(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_calibrated
*
* Whether the motor has been calibrated.
*
* Endpoint ID: 50
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_calibrated(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_I_cal
*
* The calibration current.
*
* Endpoint ID: 51
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_I_cal(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_motor_errors
*
* Any motor/calibration errors, as a bitmask
*
* Endpoint ID: 52
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_motor_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_onboard_calibrated
*
* Whether the sensor has been calibrated.
*
* Endpoint ID: 53
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_onboard_calibrated(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_onboard_errors
*
* Any sensor errors, as a bitmask
*
* Endpoint ID: 54
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_onboard_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_external_spi_type
*
* The type of external sensor type. Either MA7XX, AS5047 or AMT22.
*
* Endpoint ID: 55
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_external_spi_type(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_external_spi_calibrated
*
* Whether the sensor has been calibrated.
*
* Endpoint ID: 56
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_external_spi_calibrated(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_external_spi_errors
*
* Any sensor errors, as a bitmask
*
* Endpoint ID: 57
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_external_spi_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_hall_calibrated
*
* Whether the sensor has been calibrated.
*
* Endpoint ID: 58
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_hall_calibrated(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_setup_hall_errors
*
* Any sensor errors, as a bitmask
*
* Endpoint ID: 59
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_setup_hall_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_position_type
*
* The angle sensor type. Either ONBOARD, EXTERNAL_SPI or HALL.
*
* Endpoint ID: 60
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_position_type(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_position_bandwidth
*
* The sensor observer bandwidth.
*
* Endpoint ID: 61
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_position_bandwidth(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_position_position_estimate
*
* The filtered sensor position estimate.
*
* Endpoint ID: 62
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_position_position_estimate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_position_velocity_estimate
*
* The filtered sensor velocity estimate.
*
* Endpoint ID: 63
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_position_velocity_estimate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_commutation_type
*
* The angle sensor type. Either ONBOARD, EXTERNAL_SPI or HALL.
*
* Endpoint ID: 64
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_commutation_type(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_commutation_bandwidth
*
* The sensor observer bandwidth.
*
* Endpoint ID: 65
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_commutation_bandwidth(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_commutation_position_estimate
*
* The filtered sensor position estimate.
*
* Endpoint ID: 66
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_commutation_position_estimate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_sensors_select_commutation_velocity_estimate
*
* The filtered sensor velocity estimate.
*
* Endpoint ID: 67
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_sensors_select_commutation_velocity_estimate(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_max_accel
*
* The max allowed acceleration of the generated trajectory.
*
* Endpoint ID: 68
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_max_accel(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_max_decel
*
* The max allowed deceleration of the generated trajectory.
*
* Endpoint ID: 69
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_max_decel(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_max_vel
*
* The max allowed cruise velocity of the generated trajectory.
*
* Endpoint ID: 70
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_max_vel(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_t_accel
*
* In time mode, the acceleration time of the generated trajectory.
*
* Endpoint ID: 71
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_t_accel(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_t_decel
*
* In time mode, the deceleration time of the generated trajectory.
*
* Endpoint ID: 72
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_t_decel(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_t_total
*
* In time mode, the total time of the generated trajectory.
*
* Endpoint ID: 73
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_t_total(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_move_to
*
* Move to target position respecting velocity and acceleration limits.
*
* Endpoint ID: 74
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_move_to(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_move_to_tlimit
*
* Move to target position respecting time limits for each sector.
*
* Endpoint ID: 75
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_move_to_tlimit(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_traj_planner_errors
*
* Any errors in the trajectory planner, as a bitmask
*
* Endpoint ID: 76
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_traj_planner_errors(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_velocity
*
* The velocity at which the motor performs homing.
*
* Endpoint ID: 77
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_velocity(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_max_homing_t
*
* The maximum time the motor is allowed to travel before homing times out and aborts.
*
* Endpoint ID: 78
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_max_homing_t(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_retract_dist
*
* The retraction distance the motor travels after the endstop has been found.
*
* Endpoint ID: 79
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_retract_dist(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_warnings
*
* Any homing warnings, as a bitmask
*
* Endpoint ID: 80
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_warnings(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_stall_detect_velocity
*
* The velocity below which (and together with `stall_detect.delta_pos`) stall detection mode is triggered.
*
* Endpoint ID: 81
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_stall_detect_velocity(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_stall_detect_delta_pos
*
* The velocity below which (and together with `stall_detect.delta_pos`) stall detection mode is triggered.
*
* Endpoint ID: 82
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_stall_detect_delta_pos(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_stall_detect_t
*
* The time to remain in stall detection mode before the motor is considered stalled.
*
* Endpoint ID: 83
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_stall_detect_t(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_homing_home
*
* Perform the homing operation.
*
* Endpoint ID: 84
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_homing_home(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_watchdog_enabled
*
* Whether the watchdog is enabled or not.
*
* Endpoint ID: 85
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_watchdog_enabled(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_watchdog_triggered
*
* Whether the watchdog has been triggered or not.
*
* Endpoint ID: 86
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_watchdog_triggered(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

/*
* avlos_watchdog_timeout
*
* The watchdog timeout period.
*
* Endpoint ID: 87
*
* @param buffer
* @param buffer_len
*/
uint8_t avlos_watchdog_timeout(uint8_t * buffer, uint8_t * buffer_len, Avlos_Command cmd);

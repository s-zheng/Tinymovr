
//  * This file is part of the Tinymovr-Firmware distribution
//  * (https://github.com/yconst/tinymovr-firmware).
//  * Copyright (c) 2020-2023 Ioannis Chatzikonstantinou.
//  *
//  * This program is free software: you can redistribute it and/or modify
//  * it under the terms of the GNU General Public License as published by
//  * the Free Software Foundation, version 3.
//  *
//  * This program is distributed in the hope that it will be useful, but
//  * WITHOUT ANY WARRANTY; without even the implied warranty of
//  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
//  * General Public License for more details.
//  *
//  * You should have received a copy of the GNU General Public License
//  * along with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "pac5xxx.h"
#include "pac5xxx_adc.h"
#include "pac5xxx_can.h"
#include "pac5xxx_crc.h"
#include "pac5xxx_gp_timers.h"
#include "pac5xxx_gpio.h"
#include "pac5xxx_i2c.h"
#include "pac5xxx_memory.h"
#include "pac5xxx_rtc.h"
#include "pac5xxx_scc.h"
#include "pac5xxx_ssp.h"
#include "pac5xxx_timers.h"
#include "pac5xxx_uart.h"
#include "pac5xxx_wwdt.h"
#include "pac5xxx_driver_adc.h"
#include "pac5xxx_driver_can.h"
#include "pac5xxx_driver_config.h"
#include "pac5xxx_driver_gpio.h"
#include "pac5xxx_driver_memory.h"
#include "pac5xxx_driver_socbridge.h"
#include "pac5xxx_driver_system.h"
#include "pac5xxx_driver_tile.h"
#include "pac5xxx_driver_timer.h"
#include "pac5xxx_driver_uart.h"
#include "pac5527.h"
#include "pac5xxx_tile_power_manager.h"
#include "pac5xxx_tile_signal_manager.h"
#include "config.h"

#define ALWAYS_INLINE __attribute__((always_inline)) 

#ifndef PAC5XXX_OK
#define PAC5XXX_OK 0
#endif

#ifndef PAC5XXX_ERROR
#define PAC5XXX_ERROR 1
#endif

#if defined(DEBUG)
#define TM_RAMFUNC
#elif defined (NDEBUG)
#define TM_RAMFUNC PAC5XXX_RAMFUNC
// We'll also define PAC5XXX_DRIVER_TILE_RAM in the Makefile
#else
#error "Unknown debug configuration"
#endif

#define BTL_TRIGGER_PATTERN  0x39
#define BTL_TRIGGER_PATTERN_RAM  0x5048434D

#define PI (3.141592f)
#define TWOPI (6.283185f)
#define INVTWOPI (0.159155f)
#define EPSILON (2.718281f)

// #define ROSCCLK_FREQ_HZ              (16000000)

#define PWM_PERIOD_S (1.0f / PWM_FREQ_HZ)

#define READ_UINT16(address) (*((uint16_t *)address))
#define READ_UINT32(address) (*((uint32_t *)address))

#define ERROR_FLAG_MAX_SIZE (5u)

#if defined BOARD_REV_R32 || defined BOARD_REV_R33
#define BOARD_REV_R3
#elif defined BOARD_REV_R50 || BOARD_REV_R51 || defined BOARD_REV_R52 || defined BOARD_REV_R53
#define BOARD_REV_R5
#elif defined BOARD_REV_M51
#define BOARD_REV_M5
#else
#error "Board revision incorrect or not defined"
#endif

#if defined BOARD_REV_R3
#define CAN_PE23
#elif defined BOARD_REV_R5
#define CAN_PF67
#elif defined BOARD_REV_M5
#define CAN_PD56
#endif

#if defined BOARD_REV_R32
#define BOARD_REV_IDX 2
#elif defined BOARD_REV_R33
#define BOARD_REV_IDX 3
#elif defined BOARD_REV_R50
#define BOARD_REV_IDX 10
#elif defined BOARD_REV_R51
#define BOARD_REV_IDX 11
#elif defined BOARD_REV_R52
#define BOARD_REV_IDX 12
#elif defined BOARD_REV_R53
#define BOARD_REV_IDX 13
#elif defined BOARD_REV_M50
#define BOARD_REV_IDX 20
#elif defined BOARD_REV_M51
#define BOARD_REV_IDX 21
#endif

#if defined BOARD_REV_R3 || defined BOARD_REV_R5
#define MIN_TRIP_CURRENT (5.0f) // A
#elif defined BOARD_REV_M5
#define MIN_TRIP_CURRENT (1.0f) // A
#endif

#define TIMER_FREQ_HZ (ACLK_FREQ_HZ >> TXCTL_PS_DIV)

#define SENSOR_COMMON_RES_BITS (13)
#define SENSOR_COMMON_RES_TICKS (1 << SENSOR_COMMON_RES_BITS)
#define SENSOR_COMMON_RES_HALF_TICKS (SENSOR_COMMON_RES_TICKS/2)
#define SENSOR_COMMON_RES_TICKS_FLOAT ((float)(SENSOR_COMMON_RES_TICKS))

#define MOTOR_MAX_POLE_PAIRS 24

static const float one_by_sqrt3 = 0.57735026919f;
static const float two_by_sqrt3 = 1.15470053838f;
static const float threehalfpi = 4.7123889f;
static const float pi = PI;
static const float halfpi = PI * 0.5f;
static const float quarterpi = PI * 0.25f;
static const float twopi_by_common_ticks = TWOPI / SENSOR_COMMON_RES_TICKS;

_Static_assert(TIMER_FREQ_HZ % (2*PWM_FREQ_HZ) == 0, "Timer frequency not an integer multiple of PWM frequency");

typedef struct 
{
	float A;
	float B;
	float C;
} FloatTriplet;

static const FloatTriplet three_phase_zero = {0.5f, 0.5f, 0.5f};

#endif // #ifndef COMMON_H

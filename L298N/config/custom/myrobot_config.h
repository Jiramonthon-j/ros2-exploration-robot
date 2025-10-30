// Copyright (c) 2021 Juan Miguel Jimeno
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MYROBOT_CONFIG_H
#define MYROBOT_CONFIG_H

#define LED_PIN 2
#define ESP32
#define SOC_PCNT_SUPPORTED
#define BAUDRATE 115200
#define LINO_BASE DIFFERENTIAL_DRIVE 

#define USE_GENERIC_2_IN_MOTOR_DRIVER 
#define USE_GY85_IMU
//#define USE_MPU6050_IMU
#define SDA_PIN 21 // specify I2C pins for esp32
#define SCL_PIN 22

// #define USE_LIDAR_UDP
// #define LIDAR_RXD 17 // you may use any available input pin
// // #define LIDAR_PWM 15  // do not use, the PWM control loop is not implememted yet
// #define LIDAR_SERIAL 1 // uart number, 1 or 2
// #define LIDAR_BAUDRATE 230400 // the Lidar serial buadrate
// #define LIDAR_SERVER { 192, 168, 1, 145 }  // eg your desktop IP addres
// #define LIDAR_PORT 8889 // the UDP port on server


#define KP_L 10.0     // 30                        
#define KI_L 5.0                             
#define KD_L 0.1

#define KP_R 10.0                             
#define KI_R 5.0                             
#define KD_R 0.1                             
                             

#define MOTOR_MAX_RPM 110       
#define MAX_RPM_RATIO 0.8
#define MOTOR_OPERATING_VOLTAGE 12
#define MOTOR_POWER_MAX_VOLTAGE 12
#define MOTOR_POWER_MEASURED_VOLTAGE 12.0    
        
#define COUNTS_PER_REV1 836 //960
#define COUNTS_PER_REV2 779 //960

#define COUNTS_PER_REV3 240
#define COUNTS_PER_REV4 240
#define WHEEL_DIAMETER 0.065               
#define LR_WHEELS_DISTANCE 0.2            
#define PWM_BITS 10                         
#define PWM_FREQUENCY 20000

// Fixed pin numbers for ESP32-WROOM-32D 30 PIN VERSION
/// ENCODER PINS
#define MOTOR1_ENCODER_A 34
#define MOTOR1_ENCODER_B 35 
#define MOTOR1_ENCODER_INV true 

#define MOTOR2_ENCODER_A 16
#define MOTOR2_ENCODER_B 27 
#define MOTOR2_ENCODER_INV false



// Motor Pins
#define MOTOR1_PWM 14
#define MOTOR1_IN_A 12
#define MOTOR1_IN_B 13 
#define MOTOR1_INV true

#define MOTOR2_PWM 33
#define MOTOR2_IN_A 26
#define MOTOR2_IN_B 25 
#define MOTOR2_INV false

#define PWM_MAX pow(2, PWM_BITS) - 1
#define PWM_MIN -(pow(2, PWM_BITS) - 1)

#endif

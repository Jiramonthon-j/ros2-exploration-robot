// Copyright (c) 2025 Jamorn Saksommon
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

#ifndef DEFAULT_MOTOR
#define DEFAULT_MOTOR

#include <Arduino.h>
#include <ESP32Servo.h>
#include "config.h"


#ifdef ESP32
inline void analogWriteFrequency(uint8_t pin, double frequency)
{
  analogWriteFrequency(frequency);
}
#endif
#include "motor_interface.h"

class Generic2: public MotorInterface
{
    private:
        int in_a_pin_;
        int in_b_pin_;
        int pwm_pin_;
        int channel_;
        
    protected:
        void forward(int pwm) override
        {
            if (in_a_pin_ < 0) return;
            
            digitalWrite(in_a_pin_, LOW);
            digitalWrite(in_b_pin_, HIGH);
            ledcWrite(channel_, constrain(pwm, PWM_MIN , PWM_MAX));    
        }

        void reverse(int pwm) override
        {
	    if (in_a_pin_ < 0) return;
            
            digitalWrite(in_a_pin_, HIGH);
            digitalWrite(in_b_pin_, LOW);
            ledcWrite(channel_, -constrain(pwm, -PWM_MAX , 0));
        }

    public:
        Generic2(int channel, float pwm_frequency, int pwm_bits, bool invert, int pwm_pin, int in_a_pin, int in_b_pin): 
            MotorInterface(invert),
            in_a_pin_(in_a_pin),
            in_b_pin_(in_b_pin),
            pwm_pin_(pwm_pin),
            channel_(channel)
        {
	    if (in_a_pin_ < 0) return;
            pinMode(in_a_pin_, OUTPUT);
            pinMode(in_b_pin_, OUTPUT);
            pinMode(pwm_pin_, OUTPUT);

            ledcSetup( channel_ ,PWM_FREQUENCY ,PWM_BITS);
            ledcAttachPin(pwm_pin_ , channel_ );
                        
            digitalWrite(in_a_pin_, LOW);
            digitalWrite(in_b_pin_, LOW);
            
        }

        void brake() override
        {
	    if (in_a_pin_ < 0) return;
            
            digitalWrite(in_a_pin_, LOW); // short brake
            digitalWrite(in_b_pin_, LOW);

        }
};

#endif


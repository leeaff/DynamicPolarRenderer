#include <Arduino.h>

#define LED_PIN1 8
#define LED_PIN2 7
#define LED_PIN3 5
#define LED_PIN4 10

#define NUM_LEDS 4

// Array of LED pins for easy iteration
const int ledPins[NUM_LEDS] = {LED_PIN1, LED_PIN2, LED_PIN3, LED_PIN4};

// Function to display LED states using multiplexing
// Pass in desired states: 1 = ON, 0 = OFF
// iterations: how many times to cycle through all LEDs
// delayTime: microseconds between each LED (lower = smoother, try 500-2000)
void displayLEDs(bool led1, bool led2, bool led3, bool led4, int iterations = 4, int delayTime = 5000) {
  bool states[NUM_LEDS] = {led1, led2, led3, led4};
  
  for (int i = 0; i < iterations; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      if (states[j]) {
        digitalWrite(ledPins[j], HIGH);
        delayMicroseconds(delayTime);
        digitalWrite(ledPins[j], LOW);
      } else {
        // Even if OFF, we still need to spend time here to keep timing consistent
        delayMicroseconds(delayTime);
      }
    }
  }
}

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
}

void loop() {
  // LED1 and LED3 ON at the same time
  displayLEDs(true, true, true, true);
  delay(800);
  
  // LED2 and LED4 ON at the same time
  displayLEDs(false, false, false, true);
  delay(800);
  
  // LED1, LED2, and LED3 ON at the same time
  displayLEDs(true, true, true, false);
  delay(800);
  
  // All LEDs ON at the same time
  displayLEDs(true, true, true, true);
  delay(800);
}


// #include "driver/pcnt.h"

// #define ENC_A 32          // Encoder channel A
// #define ENC_B 33          // Encoder channel B

// // CHANGE THIS BASED ON YOUR MOTOR
// // CPR = pulses_per_motor_rev × gear_ratio × 4
// #define CPR 2400          // Example: 12 PPR × 50:1 × 4 = 2400

// #define PCNT_UNIT_USED PCNT_UNIT_0

// int16_t lastCount = 0;
// unsigned long lastTime = 0;

// void setupEncoder() {
//   pcnt_config_t pcnt_config = {
//     .pulse_gpio_num = ENC_A,
//     .ctrl_gpio_num  = ENC_B,
//     .lctrl_mode     = PCNT_MODE_REVERSE,
//     .hctrl_mode     = PCNT_MODE_KEEP,
//     .pos_mode       = PCNT_COUNT_INC,
//     .neg_mode       = PCNT_COUNT_DEC,
//     .counter_h_lim  = 32767,
//     .counter_l_lim  = -32768
//     .channel        = PCNT_CHANNEL_0,
//     .unit           = PCNT_UNIT_USED,
//   };

//   pcnt_unit_config(&pcnt_config);

//   pcnt_counter_pause(PCNT_UNIT_USED);
//   pcnt_counter_clear(PCNT_UNIT_USED);
//   pcnt_counter_resume(PCNT_UNIT_USED);
// }

// void setup() {
//   Serial.begin(115200);
//   delay(1000);

//   pinMode(ENC_A, INPUT_PULLUP);
//   pinMode(ENC_B, INPUT_PULLUP);

//   setupEncoder();

//   lastTime = millis();

//   Serial.println("ESP32 Encoder Ready");
// }

// void loop() {
//   int16_t count = 0;
//   pcnt_get_counter_value(PCNT_UNIT_USED, &count);

//   unsigned long now = millis();
//   float dt = (now - lastTime) / 1000.0;

//   if (dt > 0) {
//     int delta = count - lastCount;

//     // Speed (RPM)
//     float rpm = (delta / (float)CPR) * (60.0 / dt);

//     // Angle (0–360 degrees)
//     float angle = fmod((float)count, (float)CPR) * (360.0 / CPR);
//     if (angle < 0) angle += 360.0;

//     // Output
//     Serial.print("Count: ");
//     Serial.print(count);
//     Serial.print(" | Angle: ");
//     Serial.print(angle, 2);
//     Serial.print(" deg | RPM: ");
//     Serial.println(rpm, 2);

//     lastCount = count;
//     lastTime = now;
//   }

//   delay(100);
// }

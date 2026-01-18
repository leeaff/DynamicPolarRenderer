#include "driver/pcnt.h"

#define ENC_A 32          // Encoder channel A
#define ENC_B 33          // Encoder channel B

// CHANGE THIS BASED ON YOUR MOTOR
// CPR = pulses_per_motor_rev × gear_ratio × 4
#define CPR 2400          // Example: 12 PPR × 50:1 × 4 = 2400

#define PCNT_UNIT_USED PCNT_UNIT_0

int16_t lastCount = 0;
unsigned long lastTime = 0;

void setupEncoder() {
  pcnt_config_t pcnt_config = {
    .pulse_gpio_num = ENC_A,
    .ctrl_gpio_num  = ENC_B,
    .lctrl_mode     = PCNT_MODE_REVERSE,
    .hctrl_mode     = PCNT_MODE_KEEP,
    .pos_mode       = PCNT_COUNT_INC,
    .neg_mode       = PCNT_COUNT_DEC,
    .counter_h_lim  = 32767,
    .counter_l_lim  = -32768
    .channel        = PCNT_CHANNEL_0,
    .unit           = PCNT_UNIT_USED,
  };

  pcnt_unit_config(&pcnt_config);

  pcnt_counter_pause(PCNT_UNIT_USED);
  pcnt_counter_clear(PCNT_UNIT_USED);
  pcnt_counter_resume(PCNT_UNIT_USED);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);

  setupEncoder();

  lastTime = millis();

  Serial.println("ESP32 Encoder Ready");
}

void loop() {
  int16_t count = 0;
  pcnt_get_counter_value(PCNT_UNIT_USED, &count);

  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;

  if (dt > 0) {
    int delta = count - lastCount;

    // Speed (RPM)
    float rpm = (delta / (float)CPR) * (60.0 / dt);

    // Angle (0–360 degrees)
    float angle = fmod((float)count, (float)CPR) * (360.0 / CPR);
    if (angle < 0) angle += 360.0;

    // Output
    Serial.print("Count: ");
    Serial.print(count);
    Serial.print(" | Angle: ");
    Serial.print(angle, 2);
    Serial.print(" deg | RPM: ");
    Serial.println(rpm, 2);

    lastCount = count;
    lastTime = now;
  }

  delay(100);
}

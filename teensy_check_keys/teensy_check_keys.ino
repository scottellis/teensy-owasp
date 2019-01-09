/*
 * Toggle teensy led based on state of LOCK keys 
 */
 
extern volatile uint8_t keyboard_leds;

#define NUM_LOCK 0x01
#define CAPS_LOCK 0x02
#define SCROLL_LOCK 0x04

#define LEDPIN 13

void setup() {
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  delay(3000); 
}

void flash_led(uint8_t count)
{
  for (int i = 0; i < count; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(150);
    digitalWrite(LEDPIN, LOW);
    delay(150);
  }
}

void loop() {
  flash_led(keyboard_leds);
  delay(2000);
}

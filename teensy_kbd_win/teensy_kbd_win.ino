/*
 * Run different Win payloads based on LOCK key states 
 */
 
extern volatile uint8_t keyboard_leds;

#define NUM_LOCK_BIT 0x01
#define CAPS_LOCK_BIT 0x02
#define SCROLL_LOCK_BIT 0x04

#define LEDPIN 13

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
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1((uint8_t)KEY_R);
  Keyboard.send_now();

  Keyboard.releaseAll();

  delay(1000);
  
  Keyboard.print("cmd\n");
  Keyboard.send_now();
  
  delay(1500);
  
  Keyboard.print("dir\n");
  Keyboard.send_now();
}

void send_payload_2() {   
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1((uint8_t)KEY_R);
  Keyboard.send_now();
 
  Keyboard.releaseAll();
  
  delay(1000);
  
  Keyboard.print("https://jumpnowtek.com\n");
  Keyboard.send_now();
}

void send_payload_3() {
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1((uint8_t)KEY_R);
  Keyboard.send_now();
 
  Keyboard.releaseAll();

  delay(1000);
  
  Keyboard.print("cmd\n");
  Keyboard.send_now();
  
  delay(1500);

  Keyboard.print("echo S2V5Ym9hcmQgRW11bGF0aW9uIHdpdGggYSBUZWVuc3lkdWlubw0KT1dBU1AgTWFpbmUgLSBKYW51 > %TMP%/secret\n");
  Keyboard.print("echo YXJ5IDgsIDIwMTkNClByZXNlbnRlZCBieSBTY290dCBFbGxpcywgSnVtcG5vdyBUZWNobm9sb2dp >> %TMP%/secret\n");
  Keyboard.print("echo ZXMNCg== >> %TMP%/secret\n");
  Keyboard.send_now();

  Keyboard.print("certutil -decode %TMP%/secret %TMP%/message\n");
  Keyboard.send_now();
  
  Keyboard.print("notepad.exe %TMP%/message\n");
  Keyboard.send_now();

  Keyboard.print("exit\n");
  Keyboard.send_now();
}

void setup() {  
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  delay(3000);
}

void loop() {
  uint8_t current_state = keyboard_leds;

  // a little debouncing
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
        
      case 4:
      case 5:
      case 6:
      case 7:
        break;
    }
  }

  old_state = current_state;
  
  delay(1000);
}

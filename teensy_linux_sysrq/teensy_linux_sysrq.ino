/*
 * Run a linux sysrq command
 */
 
#define CMD_REBOOT  KEY_B
#define CMD_PWROFF  KEY_O
#define CMD_KILL_PS KEY_E

#define RUN_CMD     CMD_PWROFF

bool done;

void setup() {
  delay(3000);
}

void loop() { 
  if (!done) {
    done = true;

    Keyboard.set_modifier(MODIFIERKEY_ALT);
    Keyboard.set_key1((uint8_t)KEY_PRINTSCREEN);    
    Keyboard.set_key2((uint8_t)RUN_CMD);
    Keyboard.send_now();

    Keyboard.releaseAll();
  }
}

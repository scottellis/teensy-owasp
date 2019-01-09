/*
 * Start a cmd shell
 */
 
bool done;

void setup() {
  delay(3000);
}

void loop() {   
  if (!done) {
    done = true;  
    
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
    Keyboard.set_key1((uint8_t)KEY_R);
    Keyboard.send_now();
    Keyboard.releaseAll();

    delay(1000);

    Keyboard.println("cmd");
  }
}

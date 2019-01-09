/*
 * Launch notepad and do some work
 */
 
bool notepad_started;
int lines;

void setup() {
  delay(3000);
}

void loop() {   
  if (!notepad_started) {
    notepad_started = true;  
    
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
    Keyboard.set_key1((uint8_t)KEY_R);
    Keyboard.send_now();
    Keyboard.releaseAll();
    
    delay(500);
  
    Keyboard.println("notepad.exe");
  }
  else {
    if (lines < 10) {
      Keyboard.println("All work and no play makes Jack a dull boy.");
      lines++;
    }
  }

  delay(1500);
}

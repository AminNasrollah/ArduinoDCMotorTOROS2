  #ifdef ARDUINO_ENC_COUNTER
  #define LEFT_ENC_PIN_A PD2   // pin 2
  #define LEFT_ENC_PIN_B PD3   // pin 3
  
  #define RIGHT_ENC_PIN_A PC4  // pin A4
  #define RIGHT_ENC_PIN_B PC5  // pin A5
#endif
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

#ifdef ARDUINO_ENC_COUNTER
  #define LEFT_ENC_PIN_A PD2   // pin 2
  #define LEFT_ENC_PIN_B PD3   // pin 3
 
  #define RIGHT_ENC_PIN_A PC4  // pin A4
  #define RIGHT_ENC_PIN_B PC5  // pin A5
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();


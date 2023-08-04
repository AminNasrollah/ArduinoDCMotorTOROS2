#ifdef USE_BASE
#ifdef ROBOGAIA
  #include "MegaEncoderCounter.h"
  MegaEncoderCounter encoders = MegaEncoderCounter(4);   
#ifdef USE_BASE
#ifdef ROBOGAIA
  #include "MegaEncoderCounter.h"
  MegaEncoderCounter encoders = MegaEncoderCounter(4); 
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }
#elif defined(ARDUINO_ENC_COUNTER)
  volatile long left_enc_pos = 0L;
  volatile long right_enc_pos = 0L;
  static const int8_t ENC_STATES [] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};
  ISR (PCINT2_vect){
  	static uint8_t enc_last=0;
	enc_last <<=2;
	enc_last |= (PIND & (3 << 2)) >> 2;
  	left_enc_pos += ENC_STATES[(enc_last & 0x0f)];
  }
  ISR (PCINT1_vect){
        static uint8_t enc_last=0;
	enc_last <<=2;
	enc_last |= (PINC & (3 << 4)) >> 4;
  
  	right_enc_pos += ENC_STATES[(enc_last & 0x0f)];
  }
  long readEncoder(int i) {
    if (i == LEFT) return left_enc_pos;
    else return right_enc_pos;
  }
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_pos=0L;
      return;
    } else { 
      right_enc_pos=0L;
      return;
    }
  }
#else
  #error A encoder driver must be selected!
#endif
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}
#endif


#define BTS_RPwm 2
#define BTS_LPwm 4

const int  Channel_15 = 15 ;// & PWM channel 0, for BTS pin L_PWM 
const int  Channel_14 = 14 ;// & PWM channel 1, for BTS pin R_PWM 

const int freq = 1000;//  Set up PWM Frequency
const int  res = 8;//  Set up PWM Resolution 
void setup() {
  // put your setup code here, to run once:
  
  ledcSetup(Channel_15, freq,res) ; // setup PWM channel for BST L_PWM
  ledcSetup(Channel_14, freq,res) ; // setup PWM channel for BST R_PWM
  ledcAttachPin( BTS_LPwm , Channel_15) ; // Attach BST L_PWM
  ledcAttachPin( BTS_RPwm , Channel_14) ; // Attach BST R_PWM

}

void loop() {
   ledcWrite(Channel_14,100);    
   ledcWrite(Channel_15,0);

}

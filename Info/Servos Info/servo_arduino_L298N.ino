//2 Servos with L298N dual bridge and Arduino Uno v 0.1:
//
//For the first test run, set MAX_DUTYCYCLE to 75 in order to lower the maximum torque in case something goes wrong.
//When connecting the servo to the microcontroller for the first time, you have to consider the rotational direction of your wiper motor!
//Adjust the potentiometer defining the setpoint to the center position.
//If the servo moves to neutral position, too after connecting the circuit to the supply voltage, the polarity of the servo sensor is correct.
//If the wiper motor starts spinning away from the center position, the polarity of the servo motor at the output of the h brige has to be swapped.
//
//
//Source & info: www.HomoFaciens.de/technics-computer-arduino-uno_en_navion.htm


//#include <avr/io.h>
//#include <util/delay.h>


int ADC_SetPoint_S1 = 0;
int ADC_SetPointOld_S1 = 0;
int ADC_ServoPoti_S1 = 0;
int ADC_ServoPotiOld_S1 = 0;
int dutyCycle_S1 = 50; // 10 - 255
int ADCdiff_S1 = 0;
int timeDiff_S1 = 0;


int ADC_SetPoint_S2 = 0;
int ADC_SetPointOld_S2 = 0;
int ADC_ServoPoti_S2 = 0;
int ADC_ServoPotiOld_S2 = 0;
int dutyCycle_S2 = 50; // 10 - 255
int ADCdiff_S2 = 0;
int timeDiff_S2 = 0;


//Change values below to adapt your motor
//Set MAX_DUTYCYCLE_S1 and MAX_DUTYCYCLE_S2 to 75 for the first test run!

#define P_FRACTION_S1 0.3          //0.0 - 10.0 (0.3)
#define I_FRACTION_S1 0.3          //0.0 - 10.0 (0.3)
#define D_FRACTION_S1 4.0          //0.0 - 10.0 (4.0)
#define V_WINDOW_S1 25             //10 - 1000 (25)
#define MIN_DUTYCYCLE_S1 25        //0 - 255 (25)
#define MAX_DUTYCYCLE_S1 200       //0 - 255 (255)
#define SOFT_START_S1 0.3          //0.00 - 1.00 (0.30) 1.00 = OFF
#define EMERGENCY_SHUTDOWN_S1 300  //0 - 1000 (300), 0 - OFF, Stops motor if blocked

#define P_FRACTION_S2 0.3          //0.0 - 10.0 (0.3)
#define I_FRACTION_S2 0.3          //0.0 - 10.0 (0.3)
#define D_FRACTION_S2 4.0          //0.0 - 10.0 (4.0)
#define V_WINDOW_S2 25             //10 - 1000 (25)
#define MIN_DUTYCYCLE_S2 25        //0 - 255 (25)
#define MAX_DUTYCYCLE_S2 200       //0 - 255 (255)
#define SOFT_START_S2 0.3          //0.00 - 1.00 (0.30) 1.00 = OFF
#define EMERGENCY_SHUTDOWN_S2 300  //0 - 1000 (300), 0 - OFF, Stops motor if blocked


#define L289N_PWM_1 3            //INPUT A at L298N
#define L289N_PWM_2 5            //INPUT B at L298N
#define SERVO_SENSOR_S1 A0       //Analog input servo sensor
#define POTI_S1 A1               //Analog input potentiometer

#define L289N_PWM_3 6            //INPUT C at L298N
#define L289N_PWM_4 9            //INPUT D at L298N
#define SERVO_SENSOR_S2 A2       //Analog input servo sensor
#define POTI_S2 A3               //Analog input potentiometer


void setup(){
  pinMode(L289N_PWM_1, OUTPUT);     
  pinMode(L289N_PWM_2, OUTPUT);     
  pinMode(L289N_PWM_3, OUTPUT);     
  pinMode(L289N_PWM_4, OUTPUT);     

  pinMode(SERVO_SENSOR_S1, INPUT);     
  pinMode(POTI_S1, INPUT);     
  pinMode(SERVO_SENSOR_S2, INPUT);     
  pinMode(POTI_S2, INPUT);     
  
} 

 
void loop(){ 

  //Servo 1 ----------------------------------------------------------
  ADC_ServoPoti_S1 = analogRead(SERVO_SENSOR_S1);     // reads the servo sensor (between 0 and 1023) 
  ADC_SetPoint_S1 = analogRead(POTI_S1);             
    
  ADCdiff_S1 = ADC_SetPoint_S1 - ADC_ServoPoti_S1;
  
  dutyCycle_S1 = abs(ADCdiff_S1) * P_FRACTION_S1;
  dutyCycle_S1 += timeDiff_S1 * I_FRACTION_S1;
  dutyCycle_S1 += abs(ADC_SetPointOld_S1 - ADC_SetPoint_S1) * D_FRACTION_S1;
    
  if(SOFT_START_S1 * timeDiff_S1 < 1){
    dutyCycle_S1 = dutyCycle_S1 * (SOFT_START_S1 * timeDiff_S1);
  }
  
  timeDiff_S1++;
  
  if(dutyCycle_S1 < MIN_DUTYCYCLE_S1 && dutyCycle_S1 > 0){
    dutyCycle_S1 = MIN_DUTYCYCLE_S1;
  }
  
  if(dutyCycle_S1 > MAX_DUTYCYCLE_S1){
    dutyCycle_S1 = MAX_DUTYCYCLE_S1;
  }
  
  if(dutyCycle_S1 < 0){
    dutyCycle_S1 = 0;
  }
  
  
  if(abs(ADCdiff_S1) < V_WINDOW_S1){
    dutyCycle_S1 = 0;
    timeDiff_S1 = 0;
  }

  if(dutyCycle_S1 == MAX_DUTYCYCLE_S1 && timeDiff_S1 > EMERGENCY_SHUTDOWN_S1 && EMERGENCY_SHUTDOWN_S1 > 0){
    analogWrite(L289N_PWM_2, 0);
    analogWrite(L289N_PWM_1, 0);
    delay(1000);
    timeDiff_S1 = 0;
  }
  else{  
    if(ADCdiff_S1 > 0){
      analogWrite(L289N_PWM_1, 0);
      analogWrite(L289N_PWM_2, dutyCycle_S1);
    }
    if(ADCdiff_S1 < 0){
      analogWrite(L289N_PWM_1, dutyCycle_S1);
      analogWrite(L289N_PWM_2, 0);
    }
  }
  

  ADC_SetPointOld_S1 = ADC_SetPoint_S1;
  ADC_ServoPotiOld_S1 = ADC_ServoPoti_S1;


  //Servo 2 ----------------------------------------------------------
  ADC_ServoPoti_S2 = analogRead(SERVO_SENSOR_S2);     // reads the servo sensor (between 0 and 1023) 
  ADC_SetPoint_S2 = analogRead(POTI_S2);             
    
  ADCdiff_S2 = ADC_SetPoint_S2 - ADC_ServoPoti_S2;
  
  dutyCycle_S2 = abs(ADCdiff_S2) * P_FRACTION_S2;
  dutyCycle_S2 += timeDiff_S2 * I_FRACTION_S2;
  dutyCycle_S2 += abs(ADC_SetPointOld_S2 - ADC_SetPoint_S2) * D_FRACTION_S2;
    
  if(SOFT_START_S2 * timeDiff_S2 < 1){
    dutyCycle_S2 = dutyCycle_S2 * (SOFT_START_S2 * timeDiff_S2);
  }
  
  timeDiff_S2++;
  
  if(dutyCycle_S2 < MIN_DUTYCYCLE_S2 && dutyCycle_S2 > 0){
    dutyCycle_S2 = MIN_DUTYCYCLE_S2;
  }
  
  if(dutyCycle_S2 > MAX_DUTYCYCLE_S2){
    dutyCycle_S2 = MAX_DUTYCYCLE_S2;
  }
  
  if(dutyCycle_S2 < 0){
    dutyCycle_S2 = 0;
  }
  
  
  if(abs(ADCdiff_S2) < V_WINDOW_S2){
    dutyCycle_S2 = 0;
    timeDiff_S2 = 0;
  }

  if(dutyCycle_S2 == MAX_DUTYCYCLE_S2 && timeDiff_S2 > EMERGENCY_SHUTDOWN_S2 && EMERGENCY_SHUTDOWN_S2 > 0){
    analogWrite(L289N_PWM_4, 0);
    analogWrite(L289N_PWM_3, 0);
    delay(1000);
    timeDiff_S2 = 0;
  }
  else{  
    if(ADCdiff_S2 > 0){
      analogWrite(L289N_PWM_3, 0);
      analogWrite(L289N_PWM_4, dutyCycle_S2);
    }
    if(ADCdiff_S2 < 0){
      analogWrite(L289N_PWM_3, dutyCycle_S2);
      analogWrite(L289N_PWM_4, 0);
    }
  }
  

  ADC_SetPointOld_S2 = ADC_SetPoint_S2;
  ADC_ServoPotiOld_S2 = ADC_ServoPoti_S2;


  delay(15);                             // wait for the servo to get there 

}




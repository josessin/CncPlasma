// connect motor controller pins to Arduino digital pins
// motor one
int enA = 6;
int in1 = 5;
int in2 = 4;

void setup()
{
 // set all the motor control pins to outputs
 pinMode(enA, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);

}
void demoOne()
{
// this function will run the motors in both directions at a fixed speed
 // turn on motor A
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enA, 255);
 
 delay(2000);
 // now change motor directions
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 
 delay(2000);
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);

}
void demoTwo()
{
 // this function will run the motors across the range of possible speeds
 // note that maximum speed is determined by the motor itself and the
//operating voltage
 // the PWM values sent by analogWrite() are fractions of the maximum
//speed possible
 // by your hardware
 // turn on motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);

 // accelerate from zero to maximum speed
 for (int i = 0; i < 256; i++)
 {
 analogWrite(enA, i);
 delay(20);
 }
 // decelerate from maximum speed to zero
 for (int i = 255; i >= 0; --i)
 {
 analogWrite(enA, i);
 delay(20);
 }
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
}
void loop()
{
 demoOne();
 delay(1000);
 demoTwo();
 delay(1000);
}


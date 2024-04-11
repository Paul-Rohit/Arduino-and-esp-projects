#include <Servo.h>
//PID constants
double kp = 2;
double ki = 5;
double kd = 1;
Servo myServo;
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint;
double cumError, rateError;

void setup(){
        Serial.begin(9600);
        myServo.attach(3);
        setPoint = 90;                          //set point at zero degrees
        myServo.write(setPoint);
}    

void loop(){
        input = analogRead(A0);                //read from rotary encoder connected to A0
        output = computePID(input);
        myServo.write(output);                //control the motor based on PID value
        Serial.println("Out:");
        Serial.println(output);
        Serial.print(",");
        Serial.println("Input:");
        Serial.println(input);
        delay(100);

}

double computePID(double inp){     
        currentTime = millis();                //get current time
        elapsedTime = (double)(currentTime - previousTime);        //compute time elapsed from previous computation
        
        error = setPoint - inp;                                // determine error
        cumError += error * elapsedTime;                // compute integral
        rateError = (error - lastError)/elapsedTime;   // compute derivative

        double out = kp*error + ki*cumError + kd*rateError;                //PID output               

        lastError = error;                                //remember current error
        previousTime = currentTime;                        //remember current time

        return out;                                        //have function return the PID output
}

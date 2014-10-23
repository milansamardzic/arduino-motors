/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13

int motor_pin1=4;
int motor_pin2=5;
int motor_pin3=9;
int motor_pin4=8;
float desniPogled=0;
float lijeviPogled=0;
int incomingByte = 0;
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
  {
  Serial.begin(9600);
      pinMode(motor_pin1,OUTPUT);
      pinMode(motor_pin2,OUTPUT); 
      pinMode(motor_pin3,OUTPUT);
      pinMode(motor_pin4,OUTPUT); 
      Serial.print("Commands:\n > w - forward\n > s - back\n > a - turn left\n > d - turn right\n > x - stop\n > q - right motor forward\n > e - right motor back\n > r - left motor forward\n > t - left motor back\n\n");     
      delay(700);
  }
  


void rightForward(){
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      return;
}

void rightBack(){
      digitalWrite(motor_pin3,HIGH);
      digitalWrite(motor_pin4,LOW);
      return;
}

void leftForward(){
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      return;

}

void leftBack() {
      digitalWrite(motor_pin1,HIGH);
      digitalWrite(motor_pin2,LOW);
      return;

}

void forward() 
{       
      digitalWrite(motor_pin1,HIGH);
      digitalWrite(motor_pin2,LOW);
      digitalWrite(motor_pin3,HIGH);
      digitalWrite(motor_pin4,LOW);
      delay(1000);
      return;
     
}

void stopMotors() 
{       
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,LOW);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,LOW);
      delay(1000);
      return;
     
}

void back() 
{       
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      delay(1000);
      return;
     
}

void loop()
  {
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.println(inMsec);
  delay(1000);
  
  forward();
    
  if (cmMsec < 10)
  {
    stopMotors(); 
    
      /*
      Serial.print("----početak komande Nazad\n");
      //povratak nazad (posebna funkcija)
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      delay(2000); //vraća se nazad 2 sekunde
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin4, LOW);
      delay(1000); //pauza od sekundu
      Serial.print("----kraj komande Nazad\n");
      */
      
      Serial.print("----početak komande Desno\n");
      //okretanje desno (posebna funkcija)
      digitalWrite(motor_pin1,HIGH);
      digitalWrite(motor_pin2,LOW);
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      delay(2000); //okreće se desno 2 sekunde
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin1, LOW);
      
      desniPogled = cmMsec;
      Serial.print("----kraj komande Desno\n");
      
      Serial.print("----početak komande Lijevo\n");
      //okretanje lijevo (posebna funkcija)
      digitalWrite(motor_pin1,HIGH);
      digitalWrite(motor_pin2,LOW);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      delay(4000); //okreće se desno 4 sekunde
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin4, LOW);
      
      lijeviPogled = cmMsec;
      Serial.print("----kraj komande Lijevo\n");
      
        if (desniPogled>lijeviPogled){
            digitalWrite(motor_pin1,HIGH);
            digitalWrite(motor_pin2,LOW);
            digitalWrite(motor_pin1,LOW);
            digitalWrite(motor_pin2,HIGH);
            delay(4000); //okreće se desno 4 sekunde
            forward();
            Serial.print("----IDEM DESNO\n");
        
        }
        else if (desniPogled<lijeviPogled){
              forward();    
              Serial.print("----IDEM LIJEVO\n");
        }
        
      
  }
  else if(cmMsec > 10) {
    forward();Serial.print("----IDEM PRAVO\n");
  }
  
  
     if (Serial.available() > 0) {
                
                incomingByte = Serial.read();
       if (incomingByte == 's'){
       stopMotors(); Serial.print("Stop\n");
       }
     }
  
}

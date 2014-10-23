int motor_pin1=4;
int motor_pin2=5;
int motor_pin3=9;
int motor_pin4=8;

int incomingByte = 0;

void setup ()
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

void back() 
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

void forward() 
{       
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      delay(1000);
      return;
     
}


void vrijeme(){
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      delay(10000);
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin4, LOW);
      return;
    
}

void loop()
{
   
  
     if (Serial.available() > 0) {
                
                incomingByte = Serial.read();
                
                //esentral command forward, back and stop
                if (incomingByte == 'w')
                {
                   forward(); Serial.print("Forward\n"); delay(5000);
                }
                else if (incomingByte == 's')
                {
                  back(); Serial.print("Back\n");
                }
                else if (incomingByte == 'x')
                {
                  stopMotors(); Serial.print("Stop\n");
                }
                
                //right and left
                
                else if (incomingByte == 'a'){
                  //left
                    Serial.print("Going left");
                    stopMotors();
                    leftBack();
                    rightForward();
                  
                } 
                else if (incomingByte == 'd'){
                //right
                  Serial.print("Going right");
                    stopMotors();
                    rightBack();
                    leftForward();
                
                }
                               
                
                //additional commands
                
                else if (incomingByte =='q')
                {
                    rightForward(); Serial.print("Right forward\n");
                }
                
                else if (incomingByte =='e')
                {
                    rightBack(); Serial.print("Right back\n");
                }
                              
                
                else if (incomingByte =='r')
                {
                    leftForward();  Serial.print("Left forward\n");
                }
                
                else if (incomingByte =='t')
                {
                    leftBack(); Serial.print("Left back\n");
                }
                
                else if (incomingByte == 'v')
                {
                vrijeme();
                }
                
                else{
                Serial.print("Wrong command\nhailt system");
                    stopMotors();
                }
                
                
                
  } 
 
}

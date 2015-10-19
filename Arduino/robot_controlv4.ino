#include <String.h>
#include <Wire.h>

 
#define SLAVE_ADDRESS 0x04

const char message_size = 12;

char buf;
bool receiving;
String message_buffer;
String final_message;
int char_count;
int new_command[3] = {0,0,0};

unsigned long time_of_last_message = 0;
unsigned long current_time = 1;


int motor_1_a = 5;
int motor_1_b = 3;

int motor_3_a = 9;
int motor_3_b = 6;


int motor_2_a = 10;
int motor_2_b = 11;


float min_length = 50.0;
float max_xy_val = 10;

#define MAX_WAIT_TIME_MS 500

void setup() 
{                
  pinMode(motor_1_a, OUTPUT);
  pinMode(motor_1_b, OUTPUT);
  pinMode(motor_2_a, OUTPUT);
  pinMode(motor_2_b, OUTPUT);
  pinMode(motor_3_a, OUTPUT);
  pinMode(motor_3_b, OUTPUT);
  
  // initialize i2c as slave
 Wire.begin(SLAVE_ADDRESS);
 
 // define callbacks for i2c communication
 Wire.onReceive(receiveData);

 
 Serial.begin(9600);
 
 receiving = false;

}

void loop() {
 
 current_time = millis();
 if( current_time - time_of_last_message > MAX_WAIT_TIME_MS)
  robot_stop();
 
  
}



int findCommand( String message ){
 
 int last_coma = -1;
 for(int i=0; i<3; i++){
   int new_coma = message.indexOf(',', last_coma + 1); 
   String new_int = message.substring(last_coma+1, new_coma);
   last_coma = new_coma;
   new_command[i] = new_int.toInt();
   Serial.println(new_command[i]);
 }
 
}

// callback for received data
void receiveData(int byteCount){
  

 while(Wire.available()) {

  buf = Wire.read();
  
  if( buf == '+' ){
    receiving = true;
    char_count = 0;
    message_buffer = "";
  }  else if ( receiving ){
    char_count += 1; 
    message_buffer += buf;
    if( char_count == message_size){
      final_message = message_buffer;
      receiving = false;
      Serial.println(final_message);
      findCommand(final_message);
      time_of_last_message = millis();
      if(new_command[2] != 0 ){
       robot_stop();
       rotate(new_command[2]); 
      }else if(new_command[0] == 0 && new_command[1] == 0 ){
      robot_stop();
      }else
       move_ver2(new_command[0],new_command[1],new_command[2]);
    }
  }
  
 }
}

void move_ver2( float x , float y , float angle){

 float v_length = sqrt((x*x)+(y*y));
 float theta = atan2(x,y);


  
 float mot1_v = y*cos(PI/6 + angle) + x*sin(PI/6 + angle);
 float mot3_v = y*cos(5*PI/6 + angle) + x*sin(5*PI/6 + angle);
 float mot2_v = y*cos(3*PI/2 + angle) + x*sin(3*PI/2 + angle);
 
 float mot1_v_mapped;
 float mot2_v_mapped;
 float mot3_v_mapped;

if(mot1_v == 0)
  mot1_v_mapped = 0;
else
  mot1_v_mapped = mapFloat(abs(mot1_v),0,2*max_xy_val,0,255);

if(mot2_v == 0)
  mot2_v_mapped = 0;
else
  mot2_v_mapped = mapFloat(abs(mot2_v),0,2*max_xy_val,0,255);
  
if(mot3_v == 0)
  mot3_v_mapped = 0;
else
  mot3_v_mapped = mapFloat(abs(mot3_v),0,2*max_xy_val,0,255);



 Serial.print("mot1 ");
 Serial.print(mot1_v_mapped);
 Serial.print("mot2 ");
 Serial.print(mot2_v_mapped);
 Serial.print("mot3 ");
 Serial.print(mot3_v_mapped);
 Serial.println("");

  if(mot1_v > 0){
    motor_1_forw(   mot1_v_mapped );
  }else if (mot1_v < 0){
    motor_1_back(   mot1_v_mapped); 
  }else
    motor_1_stop();
  
  
  if(mot2_v > 0){
    motor_2_forw(   mot2_v_mapped );
  }else if (mot2_v < 0){
    motor_2_back(   mot2_v_mapped); 
  }else
    motor_1_stop();
    
  if(mot3_v > 0){
    motor_3_forw(   mot3_v_mapped );
  }else if (mot3_v < 0){
    motor_3_back(   mot3_v_mapped); 
  }else
    motor_1_stop();



}


void motor_1_stop() 
{
 // SoftPWMSetPercent(motor_1_enable, 0);
  analogWrite(motor_1_a, 0);
  analogWrite(motor_1_b, 0);
}

void motor_1_forw ( int x ) 
{
 // analogWrite(motor_1_enable, x);
 // SoftPWMSetPercent(motor_1_enable, x);
  analogWrite(motor_1_a, 0);
  analogWrite(motor_1_b, x);
}

void motor_1_back( int x ) 
{
  //analogWrite(motor_1_enable, x);
 // SoftPWMSetPercent(motor_1_enable, x);
  analogWrite(motor_1_a, x);
  analogWrite(motor_1_b, 0);
}

void motor_2_stop() 
{
  //SoftPWMSetPercent(motor_2_enable, 0);
  analogWrite(motor_2_a, 0);
  analogWrite(motor_2_b, 0);
}

void motor_2_forw(int x) 
{
  //analogWrite(motor_2_enable, x);
  //SoftPWMSetPercent(motor_2_enable, x);
  analogWrite(motor_2_a, 0);
  analogWrite(motor_2_b, x);
}

void motor_2_back( int x ) 
{
 // analogWrite(motor_2_enable, x);
  analogWrite(motor_2_a, x);
  analogWrite(motor_2_b, 0);
}

void motor_3_stop() 
{
  analogWrite(motor_3_a, 0);
  analogWrite(motor_3_b, 0);
}

void motor_3_forw(int x) 
{
 // analogWrite(motor_3_enable, x);
  analogWrite(motor_3_a, 0);
  analogWrite(motor_3_b, x);
}

void motor_3_back( int x) 
{
 // analogWrite(motor_3_enable, x);
  analogWrite(motor_3_a, x);
  analogWrite(motor_3_b, 0);
}

void robot_stop(){
 motor_1_stop();
 motor_2_stop();
 motor_3_stop();
}

void rotate( int x){
 if( x > 0){
    motor_1_forw(x);
    motor_2_back(x);
   motor_3_forw(x);
 }else if (x < 0){
   motor_1_back(abs(x));
   motor_2_forw(abs(x));
   motor_3_back(abs(x)); 
   
 }

}


float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


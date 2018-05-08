////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Bluetooth car//////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////Project Contributors: Samannoy Ghosh, Ritam Ghosh///////////////////////////////////////////////////////////////
////////Version:1.01////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////Details: Bluetooth Car with Option to control other devices with relay//////////////////////////////////////////


String voice;
int lspeed=100;
#define relay1 2    //Connect relay1 to pin 2
#define relay2 3    //Connect relay2 to pin 3
void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);       //Set relay1 as an output
  pinMode(relay2, OUTPUT);       //Set relay2 as an output
  pinMode(4,OUTPUT);             // right motor
  pinMode(5,OUTPUT);             //pwm right motor
  pinMode(7,OUTPUT);             // right motor
  pinMode(8,OUTPUT);             // left motor
  pinMode(9,OUTPUT);             //pwm left motor
  pinMode(12,OUTPUT);            // left motor
  digitalWrite(relay1, LOW);     //Switch relay1 off
  digitalWrite(relay2, LOW);     //Swtich relay2 off
}
void switchon()               //Function for turning on relays
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
}
void switchoff()              //Function for turning on relays
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}
void switchon_device1()       //Function for turning on relay1
{
  digitalWrite(relay1,HIGH);
}
void switchon_device2()           //Function for turning on relay2
{
  digitalWrite(relay2, HIGH);
}
void switchoff_device1()          //Function for turning off relay1
{
  digitalWrite(relay1, LOW);
}
void switchoff_device2()         //Function for turning off relay2
{
  digitalWrite(relay2, LOW);
}

void forward(int lspeed)          //lspeed is the base speed to control the motors
{
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  analogWrite(5,lspeed);
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
  analogWrite(9,lspeed);
}
  void reverse(int lspeed)
{
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  analogWrite(5,lspeed);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  analogWrite(9,lspeed);
}
  void left(int lspeed)
{
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  analogWrite(5,lspeed);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  analogWrite(9,lspeed);
}
  void right(int lspeed)
{
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  analogWrite(5,lspeed);
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
  analogWrite(9,lspeed);
}
   void stp()
   {
      digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  analogWrite(5,0);
  digitalWrite(8,LOW);
  digitalWrite(12,LOW);
  analogWrite(9,0);
   }
   
void loop()
{
   while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    voice += c;                //Means voice = voice + c
  }
    if (voice.length() >0)
    {
      Serial.println(voice);
      if(voice == "switch on lamp")
      {
        switchon_device1();
      }               //Initiate function switchon if voice is switch on
      else if(voice == "switch off lamp")
      {
        switchoff_device1();
      }               //Initiate function switchoff if voice is switch off
      else if(voice == "lamp on")
      {   
        digitalWrite(relay1, HIGH);
      }
      else if(voice == "lamp off")
      {
        digitalWrite(relay1, LOW);
      }
      else if(voice == "lights on")
      {   
        digitalWrite(relay1, HIGH);
      }
      else if(voice == "lights off")
      {
        digitalWrite(relay1, LOW);
      }
       else if(voice == "switch on device1")
      {
        switchon_device1();
      }
      else if(voice == "switch off device1")
      {
        switchoff_device1();
      }
      else if(voice == "switch on device2")
      {
        switchon_device2();
      }
      else if(voice == "switch off device2")
      {
        switchoff_device2();
      }
      else if(voice == "switch on all")
      {
        switchon();
      }
      else if(voice == "switch off all")
      {
        switchoff();
      }
      else if(voice == "forward")
      {
        forward(lspeed);
      }
      else if(voice == "reverse")
      {
        reverse(lspeed);
      }
      else if(voice == "backward")
      {
        reverse(lspeed);
      }
      else if(voice == "left")
      {
        left(lspeed);
      }
      else if(voice == "right")
      {
        right(lspeed);
      }
      else if(voice == "stop")
      {
        stp();
      }
      else if(voice == "increase speed")
      {
        lspeed=lspeed+20;
      }
      else if(voice == "decrease speed")
      {
        lspeed=lspeed-20;
      }
      
      voice="";         //resets the voice to string to take new input
    }
   
}

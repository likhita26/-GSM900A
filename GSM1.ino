

//Variable store text message
String textMessage;
const int red = 12;
const int green = 11;
const int blue = 10;

void SendMessage(){
 Serial.println("AT+CMGF=1");
 delay(1000);
 Serial.println("AT+CMGS=\"+918919164142\"\r");
 delay(1000);
 Serial.println("ALERT");
 delay(100);
 Serial.println((char)26);
 delay(1000);
}
void setup(){
    // set leds as OUTPUT
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);

    // by defult the led is off
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);

    // initializating serial communication
    Serial.begin(19200);

    // give time to your GSM shield log on to network
    delay(20000);

    // AtT command to set SIM900 to SMS mode
    Serial.print("AT+CMGF=1\r");
    delay(100);
}

void loop(){
  if(Serial.available()>0){
    textMessage = Serial.readString();
   textMessage.toUpperCase();
   delay(10);
  }
  if(textMessage.indexOf("REDON")>=0){
    // Turn on red
    digitalWrite(red, HIGH);
    textMessage = "";
    SendMessage();
  }
  if(textMessage.indexOf("REDOFF")>=0){
    // Turn off red
    digitalWrite(red, LOW);
    textMessage = "";
  }
  if(textMessage.indexOf("GREENON")>=0){
    // Turn on green
    digitalWrite(green, HIGH);
    textMessage = "";
    SendMessage();
  }
  if(textMessage.indexOf("GREENOFF")>=0){
    // Turn off green
    digitalWrite(green, LOW);
    textMessage = "";
  }
  if(textMessage.indexOf("BLUEON")>=0){
    // Turn on blue
    digitalWrite(blue, HIGH);
    textMessage = "";
  }
  if(textMessage.indexOf("BLUEOFF")>=0){
    // Turn off blue
    digitalWrite(blue, LOW);
    textMessage = "";
    SendMessage();
  }
  if(textMessage.indexOf("ALLON")>=0){
    // Turn on all leds
    digitalWrite(blue, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    textMessage = "";
    SendMessage();
  }
  if(textMessage.indexOf("ALLOFF")>=0){
    // Turn off all leds
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    textMessage = "";
  }
}

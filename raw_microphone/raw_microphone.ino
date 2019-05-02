
const int analog_sound = A0;    //the analog pin gives values between 0 and 1023
const int digital_sound = A1;   //the digital input pin gives values of 0 or 1
const int LEDdigital = A3;

void setup() {
  delay(1000); // wait for 1000 ms (1 second) 
  Serial.begin(9600);
  Serial.println(F("Starting up..."));
  pinMode(analog_sound, INPUT); // set the analog_sound pin as an INPUT pin 
  pinMode(digital_sound, INPUT); // set the digital_sound pin as an INPUT pin
  pinMode(LEDdigital, OUTPUT); //set the LED for the digital output as an OUTPUT pin
}

void loop() {
    int analog_audioVal = 0; //set the analog audio value to 0
    int digital_audioVal = 0; //set the digital aduio value to 0
 

    analog_audioVal = analogRead(analog_sound); //read a value between 0 and 1023 from the microphone
    digital_audioVal = digitalRead(digital_sound); //read a value of 0 or 1 (adjust sensitivity with screw)

    digitalWrite(LEDdigital, digital_audioVal); //output the digital value (0 or 1) to the LED. 


    
    Serial.print(F("Analog: "));
    Serial.println(analog_audioVal);

    Serial.print(F("Digital: "));
    Serial.println(digital_audioVal);

    delay(50);
}


/* this adds the Moving Average library
 *  The moving average library allows continiously average the last 
 *  5, 10, or 300 values 
 */
#include <movingAvg.h>

//number of samples to include in the sound moving average play with this number - values between 10 and 300 will probably work
#define SAMPLES 50
// create a variable of the type "movingAvg"
movingAvg audioAverage(SAMPLES);
// create a variable to hold the current average value
int currentAudio = 0;

//sets the pin numbers that will read from the sound module
const int  analog_sound = A0;    //the analog pin gives values between 0 and 2551
const int  digital_sound = A1;   //the digital pin gives HIGH values when sound is detected and LOW values when sound is not detected
const int  LEDGreen = 6;
const int  LEDYellow = 5;
const int  LEDRed = 3;

void setup() {
  delay(1000); // wait for 1000 ms (1 second) 
  Serial.begin(9600);
  Serial.println(F("Starting up..."));
  pinMode(analog_sound, INPUT);
  pinMode(digital_sound, INPUT);
  pinMode(LEDGreen, OUTPUT);
  pinMode(LEDYellow, OUTPUT);
  pinMode(LEDRed, OUTPUT);
 

  // zero out the audio average - make sure there's no random data in there
  audioAverage.begin();
  audioAverage.reset();
}

void loop() {
  int analog_audioVal = 0; //set the analog audio value to 0
  int digital_audioVal = 0; //set the digital audio value to 0
  analog_audioVal = analogRead(analog_sound);   //read a value between 0 and 255
  digital_audioVal = digitalRead(digital_sound);    //read a digital value (high - 1; low - 0);
  currentAudio = audioAverage.reading(analog_audioVal); //get the current audio average  

  Serial.print(F("avg: "));
  Serial.println(currentAudio);

  delay(20); //This sets the delay between each cycle

}

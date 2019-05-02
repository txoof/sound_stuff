

/* this adds the Moving Average library
 *  The moving average library allows continiously average a bunch of values
 *  
 *  install this library by clicking on Tools > Manage Library and searching for the movingAvg library 
 */
#include <movingAvg.h>

//number of samples to include in the sound moving average play with this number - values between 10 and 300 will probably work
#define SAMPLES 50
// create a variable of the type "movingAvg"
movingAvg audioAverage(SAMPLES);
// create a variable to hold the current average value
int currentAudio = 0;

//sets the pin numbers that will read from the sound module
const int  analog_sound = A0;    //the analog pin gives values between 0 and 1023

void setup() {
  delay(1000); // wait for 1000 ms (1 second) 
  Serial.begin(9600);
  Serial.println(F("Starting up..."));
  pinMode(analog_sound, INPUT); // set the analog_sound pin as an INPUT pin 

  // zero out the audio average - make sure there's no random data in there
  audioAverage.begin();
  audioAverage.reset();
}

void loop() {
  int analog_audioVal = 0; //set the analog audio value to 0
  analog_audioVal = analogRead(analog_sound);   //read a value between 0 and 1023
  currentAudio = audioAverage.reading(analog_audioVal); //get the current audio average  

  Serial.print(F("avg: "));
  Serial.println(currentAudio);

  delay(20); //This sets the delay between each cycle

}

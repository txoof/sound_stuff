
/* this adds the Moving Average library
 *  The moving average library allows continiously average a bunch of values
 *  
 *  install this library by clicking on Tools > Manage Library and searching for the movingAvg library 
 */
#include <movingAvg.h>

//number of samples to include in the sound moving average play with this number - values between 10 and 300 will probably work
//more samples will make the lights easier to read, but there is a tradeoff in instantanious accuracy
#define SAMPLES 30
// create a variable of the type "movingAvg" to hold SAMPLE number of samples
movingAvg audioAverage(SAMPLES);
// create a variable to hold the current average value
int currentAudioAvg = 0;

//sets the pin numbers that will read from the sound module
const int  analog_sound = A0;    //the analog pin gives values between 0 and 1023

//sets the pins that are attached to lights
const int Grn1 = 9;
const int Grn2 = 8;
const int Yel1 = 7;
const int Yel2 = 6;
const int Red1 = 5;
const int Red2 = 4; 


void setup() {
  delay(1000); // wait for 1000 ms (1 second) 
  Serial.begin(9600);
  Serial.println(F("Starting up..."));
  pinMode(analog_sound, INPUT); //set up the analog input pin as an INPUT pin
  //The section below this sets up all the lights
  pinMode(Grn1, OUTPUT);
  pinMode(Grn2, OUTPUT);
  pinMode(Yel1, OUTPUT);
  pinMode(Yel2, OUTPUT);
  pinMode(Red1, OUTPUT);
  pinMode(Red2, OUTPUT);

  // zero out the audio average - make sure there's no random data in there
  audioAverage.begin(); //this sets everything out
  audioAverage.reset(); //this zeros out all the values
}


// this loop runs forever over and over again
void loop() {
  int analog_audioVal = 0;
  analog_audioVal = analogRead(analog_sound);   //read a value between 0 and 1023 on the analog_sound pin

  currentAudioAvg = audioAverage.reading(analog_audioVal); //store a new reading and get the current average

  /*
   * This section of the code manages the lights 
   * HIGH is on, LOW is off
   * play with the values to get the light effect you want.
   * 
   * You can add more lights and change the range that the lights respond in by adjusting these values and adding more "if" statements
   */
 
  if (currentAudioAvg > 15) {
    digitalWrite(Grn1, HIGH);  
  } else {
    digitalWrite(Grn1, LOW);
  }

// remove the // in front of each line below to add another light. Try to add the other two lights that I've provided

//  if (currentAudioAvg > 30) {
//    digitalWrite(Grn2, HIGH);  
//  } else {
//    digitalWrite(Grn2, LOW);
//  }


  if (currentAudioAvg > 50) {
    digitalWrite(Yel1, HIGH);
  } else {
    digitalWrite(Yel1, LOW);
  }
  
  if (currentAudioAvg > 100) {
    digitalWrite(Red1, HIGH);   
  } else {
    digitalWrite(Red1, LOW);
  }
  
  
  // This prints out the current average to the serial monitor. Open the serial monitor by clicking Tools > Serial Monitor
  Serial.print(F("avg: "));
  Serial.println(currentAudioAvg);



  delay(25); // this sets the delay between each cycle of the program (values around 20-30 seem to be best)

}

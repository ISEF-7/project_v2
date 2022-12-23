#include <Arduino.h>
#include <ArduinoSTL.h> //https://registry.platformio.org/libraries/mike-matera/ArduinoSTL 
#include <ArduinoJson.h> //https://registry.platformio.org/libraries/bblanchon/ArduinoJson 
#include <lc-addrlabels.h> //https://registry.platformio.org/libraries/gitlab-airbornemint/Protothreads 
#include <RPLidar.h> //https://github.com/robopeak/rplidar_arduino
#include <Servo.h> //https://registry.platformio.org/libraries/arduino-libraries/Servo

using namespace std;

RPLidar l;

class RoadData{
};

class motorinstructions{
  int instruction_id;
  string instruction;
};


void setup() {
  cout << "s"; 
}

void loop() {

}
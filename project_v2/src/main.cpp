#include <Arduino.h>
#include <ArduinoSTL.h> //https://registry.platformio.org/libraries/mike-matera/ArduinoSTL 
#include <ArduinoJson.h> //https://registry.platformio.org/libraries/bblanchon/ArduinoJson 
#include <lc-addrlabels.h> //https://registry.platformio.org/libraries/gitlab-airbornemint/Protothreads 
#include <RPLidar.h> //https://github.com/robopeak/rplidar_arduino
#include <Servo.h> //https://registry.platformio.org/libraries/arduino-libraries/Servo

using namespace std;


//c

class hub{
  public:
  
};

class RoadData{
  public:
  vector<vector<float>> roadData_ADJMTX{};

};

class sn_instrc{
  public:
  int instruction_id;
  string instruction;
};

class intrp_instrc{
  public:
  int intp_id;
  string instruction;
};


//

//modules

RPLidar l;
Servo m1;
Servo m2;
hub Hub;

//
string servo_moduleCheck(string modulename){
  if (modulename == "m1"){
    if (m1.attached() == true){return "OK"; }
    else{return "ERR";}
  }
  if (modulename == "m2"){
    if (m2.attached() == true){return "OK";}
    else{return "ERR";}
  }
  return "NULL";
}
string lidar_moduleCheck(string modulename){}; //TODO 
string hub_moduleCheck(string modulename){}; //TODO 

void setup() {
  cout << "Booting";
}

void loop() {

}
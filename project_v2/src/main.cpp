#include <Arduino.h>
#include <ArduinoSTL.h> //https://registry.platformio.org/libraries/mike-matera/ArduinoSTL 
#include <ArduinoJson.h> //https://registry.platformio.org/libraries/bblanchon/ArduinoJson 
#include "protothreads.h" //https://registry.platformio.org/libraries/gitlab-airbornemint/Protothreads 
#include <RPLidar.h> //https://github.com/robopeak/rplidar_arduino
#include <Servo.h> //https://registry.platformio.org/libraries/arduino-libraries/Servo

using namespace std;

///////

class hub{
  public:

};

class RoadData{
  public:
    vector<vector<float>> roadData_ADJMTX{};

};

//main protothread
pt ptMain;
int MainThread(struct pt* pt){
    PT_BEGIN(pt);

    for(;;){
      //TODO main thread execution
    }
    PT_END(pt);
}

//thread for interupting main thread and executing SLAM protocol
pt ptSLAM;
int SLAMThread(struct pt* pt){
  PT_BEGIN(pt);

    for(;;){
      //TODO main thread execution
    }
  PT_END(pt);
}

class location{
  public:
    string name;
    int node_position;
};


class node : location{
  public:

};

class road{
  public:
    vector<node> body;
    float length;
    vector<int> lanes;
    float speedLimit; 
};



struct roadData{
  vector<vector<float>> adjmtx_data;
  location i_location;
  location destination;
};



///////

RPLidar l;
RPLidar* L = &l;
Servo m1;
Servo* M1 = &m1;
Servo m2;
Servo* M2 = &m2;
hub Hub;
hub* HUB = &Hub;

///////

string servo_moduleCheck(Servo servo){
  //XXX test if comparing objects by runtime memory address works, alternative is to do nested classes, and the base class has the name
  if (&servo == &m1){
    if (m1.attached() == true){return "OK"; }
    else{return "ERR";}
  }
  if (&servo == &m2){
    if (m2.attached() == true){return "OK";}
    else{return "ERR";}
  }
  return "NULL";
}
string lidar_moduleCheck(RPLidar lidar){
  rplidar_response_device_info_t info;
  if (IS_OK(lidar.getDeviceInfo(info, 100)) == true && IS_OK(lidar.waitPoint()) == true){
    return "OK";
  }
  return "ERR";
}; 
string hub_moduleCheck(hub h){
  
};

///////

void boot_servo(vector<Servo> servolist){
  for (int i=0; i<servolist.size(); i++){
    cout << "Booting Servo m" << i << " ...";
    servo_moduleCheck(servolist.at(i));
  };
}
void boot_lidar(RPLidar lidar){
  cout << "Booting RPLidar...";
  lidar_moduleCheck(lidar);

  //TODO object configuration
}
void boot_hub(hub h){
  cout << "Booting hub...";
  hub_moduleCheck(h);

  //TODO object configuration
}

///////




///////

void setup() {
  cout << "Booting";
  boot_hub(Hub);
  boot_lidar(l);
  boot_servo({m1,m2});
}

///////

void loop() {

}
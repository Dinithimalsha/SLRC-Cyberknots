//Team name:- CyberKnots

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Emitter.hpp>
#define TIME_STEP 64
#define MAX_SPEED 6.2
 
using namespace std;   
using namespace webots;
   
int main(int argc, char **argv) {

  Robot *CyberKnots_robot = new Robot();
  DistanceSensor *Lf[13];
  char Lfnames[13][7] ={"LF_1","LF_2","LF_3","LF_4","LF_5","LF_6","LF_7","LF_8","LF_9","LF_10","LF_11","end","Front"};

  DistanceSensor *PC[2];
  char PC_names[2][8] ={"PC_1" , "PC_2"};

  DistanceSensor *WF[6];
  char WFnames[6][5]={"WF_1","WF_2","WF_3","WF_4","WF_5","WF_6"};

  Emitter *emitter ;
   emitter =CyberKnots_robot->getEmitter("emitter");
  
  for(int j = 0;j<13;j++){
    Lf[j]= CyberKnots_robot->getDistanceSensor(Lfnames[j]);
    Lf[j]->enable(TIME_STEP);
  } 
  
  for (int i = 0; i < 6; i++) {
    WF[i] = CyberKnots_robot->getDistanceSensor(WFnames[i]);
    WF[i]->enable(TIME_STEP);
  }

   for (int j=0;j<2;j++){
    PC[j] = CyberKnots_robot->getDistanceSensor(PC_names[j]);
    PC[j]->enable(TIME_STEP);
  }

  Motor*wheels[2];
  char wheels_names[2][4] = {"LF","RF"};

  for (int i = 0; i < 2; i++) { 
    wheels[i] = CyberKnots_robot->getMotor(wheels_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0.0);
  }

  bool is_line = false;
  bool turn_right =false;
  bool in_line = false;
  bool turn_left = false;
  bool second_box = false;
  bool t_jun = false;
  bool doted_line = false;
  bool is_dot = false;
  bool exit_doted = false;
  bool right_WF = false;
  bool left_WF = false;
  bool wall_eject = false;
  bool turn_right_final = false;
  bool turn_left_final = false;
  bool is_piller_right = true;
  bool is_piller_left = true;
  bool second_piller_right = false;
  bool second_piller_left = false;
  bool second_box_one = false ;
  bool decision_juntion = false;
  bool one_time_m = false;
  bool even_number = false;
  bool odd_number = false;
  bool in_line_2 = false ;
  bool jun_eject = false;
  bool jun_eject_1 = false;
  bool jun_eject_2 = false;
  bool one_time_deci = true;
  bool Red = false;
  bool Blue = false;
  bool emi_send = false;
  bool d_in_line = false;

  int LS_13 = 0;
  int LS_18 = 0;
  int LS_23 = 0;
  int RS_13 = 0;
  int RS_18 = 0;
  int RS_23 = 0;
  int RSP = 0;
  int LSP = 0;
  int Total = 0;
  int D_total = 0;

  
  
  while(CyberKnots_robot->step(TIME_STEP) !=-1){

    wheels[0]->setVelocity(1.5);
    wheels[1]->setVelocity(1.5);
    
    double WF1 =WF[0]->getValue();
    double WF2 =WF[1]->getValue();
    // double WF3 =WF[2]->getValue();
    double WF4 =WF[3]->getValue();
    double WF5 =WF[4]->getValue();
    double WF6 =WF[5]->getValue();
   
    double PC_1 =PC[0]->getValue();
    double PC_2 =PC[1]->getValue();
   
    double LF1 =Lf[0]->getValue();
    double LF2 =Lf[1]->getValue();
    double LF3 =Lf[2]->getValue();
    double LF4 =Lf[3]->getValue();
    double LF5 =Lf[4]->getValue();
    double LF6 =Lf[5]->getValue();
    double LF7 =Lf[6]->getValue();
    double LF8 =Lf[7]->getValue();
    double LF9 =Lf[8]->getValue();
    double LF10 =Lf[9]->getValue();
    double LF11 =Lf[10]->getValue();
    double end =Lf[11]->getValue();
    double front =Lf[12]->getValue();
    
    //detecting the line
    if(LF1<90 && LF8>90 && LF9>90 && in_line == false){
      is_line = true ;
      in_line = true;
    }
    //line following code
    if(is_line == true && turn_right == false && turn_left == false && t_jun==false){
      if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5>90){
        wheels[0]->setVelocity(2.0);
        wheels[1]->setVelocity(2.0);
      }
      if(LF1<90 && LF2<90 && LF4<90 && LF3<90 && LF5>90 && LF8>90 && LF9>90 && LF7>90 && LF6>90){
        wheels[0]->setVelocity(2.0);
        wheels[1]->setVelocity(2.2);
      }
      if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6>90){
        wheels[0]->setVelocity(2.2);
        wheels[1]->setVelocity(2.0);
      }
      if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5<90 && LF6<90 && LF8<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90){
        turn_right = true;
        is_line = false ;
        second_box = false;
      }
       if(LF1<90 && LF2>90 && LF4<90 && LF3>90 && LF5<90 && LF6<90 && LF8<90 && LF7>90 && LF9>90 && LF10<90 && LF11>90){
        turn_right = true;
        is_line = false ;
        second_box = false;
      }
      if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6>90 && LF7<90 && LF8>90 && LF9<90 && LF10<90 && LF11<90){
        turn_left = true ;
        is_line = false;
        second_box = false;
      }
      if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6<90 && LF7<90 && LF8<90 && LF9<90 && LF10<90 && LF11<90){
        second_box = true;
        turn_right = false;
        turn_left = false;
      }
      if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6<90 && LF7<90 && LF8<90 && LF9<90 && LF10<90 && LF11>90){
        t_jun = true ;
        is_line =false;
      }
      if(WF1<700 && WF2<400){
        is_line = false;
        right_WF = true; 
      }
      if(WF5<800 && WF6<1000){
        is_line = false;
        left_WF = true;
      }
      if(LF1<90 && LF2<90 && LF3<90 && LF7<90 && LF9>90 && LF10>90 && LF11<90 && LF4>90 && LF5>90 && LF6>90 && LF8>90){
        wheels[0]->setVelocity(2);
        wheels[1]->setVelocity(2.4);
      
      }
    }
    
    //turn right code
    if(turn_right == true){
      wheels[0]->setVelocity(3);
      wheels[1]->setVelocity(-3);

      if(LF1<90 && LF2<90 && LF4<90 && LF3<90 && LF5<90 && LF6<90 && LF8>90 && LF7<90 && LF9>90 && LF10>90 && LF11<90){
        wheels[0]->setVelocity(3);
        wheels[1]->setVelocity(1);
      }
      if(LF1<90 && LF2<90 && LF4<90 && LF3<90 && LF5<90 && LF6<90 && LF8<90 && LF7<90 && LF9>90 && LF10<90 && LF11<90){
        wheels[0]->setVelocity(1);
        wheels[1]->setVelocity(1);
        turn_right = false;
        is_line = true;
        second_piller_left = false ;
      }
      //piller identifying and counting
       if(PC_1<25){
           is_piller_left = true;
       }
      if(is_piller_left == true && PC_1 <14 && second_piller_left ==false){
        if(PC_1>12.5){
          is_piller_left = false;
          LS_13 ++ ;
          second_piller_left = true;
          std::cout<<"Pillar at left side-13cm"<<"\n";
        } 
      }
      if(is_piller_left == true && PC_1<19 && second_piller_left ==false){
        if(PC_1>17.5){
          is_piller_left = false;
          LS_18 ++;
          second_piller_left = true;
          std::cout<<"Pillar at left side-18cm"<<"\n";
        } 
      }
      if(is_piller_left == true && PC_1 <24 && second_piller_left ==false){
        if(PC_1>22.5){
          is_piller_left = false;
          LS_23 ++ ;
          second_piller_left = true;
          std::cout<<"Pillar at left side-23cm"<<"\n";
        } 
      }
      if(PC_1 == 25){
       is_piller_left = true;
      }
    }
    
    //turn left code
    if(turn_left == true){
      wheels[0]->setVelocity(-3);
      wheels[1]->setVelocity(3);
      if(LF1<90 && LF2<90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11<90){
        wheels[0]->setVelocity(1);
        wheels[1]->setVelocity(3);
      }
       if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5>90 && LF6>90 && LF7<90 && LF9<90 && LF8>90 && LF10<90 && LF11<90){
        wheels[0]->setVelocity(1);
        wheels[1]->setVelocity(1);
        turn_left = false;
        is_line = true;
        second_piller_right = false ;
       }
       //piller identifying and counting
       if(PC_2<25){
           is_piller_right = true;
           }
      if(is_piller_right == true && PC_2 <14 && second_piller_right ==false){
        if(PC_2>12.5){
          is_piller_right = false;
          RS_13 ++ ;
          second_piller_right = true;
          std::cout<<"Pillar at right side-13cm"<<"\n";
        } 
      }
      if(is_piller_right == true && PC_2<19 && second_piller_right ==false){
        if(PC_2>17.5){
          is_piller_right = false;
          RS_18 ++;
          second_piller_right = true;
          std::cout<<"Pillar at right side-18cm"<<"\n";
        } 
      }
      if(is_piller_right == true && PC_2 <24 && second_piller_right ==false){
        if(PC_2>22.5){
          is_piller_right = false;
          RS_23 ++ ;
          second_piller_right = true;
          std::cout<<"Pillar at right side-23cm"<<"\n";
        } 
      }
      if(PC_2 == 25){
       is_piller_right = true;
      }
    }

    //second box code
    if(second_box == true){
        wheels[0]->setVelocity(2.0);
        wheels[1]->setVelocity(2.0);
        turn_right = false;
        turn_left = false;
        second_box = false;
        if(LF1<90 && LF2<90 && LF3>90 && LF4<90 && LF5>90 && LF6>90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11<90){
            is_line = true;
            second_piller_left = false;
            second_piller_right = false;
        }
        if(PC_1<PC_2 && second_box_one == false){
          second_box_one = true;
          std::cout<<"left side pillar is the closest"<<"\n";
        }
        if(PC_2<PC_1 && second_box_one == false){
          second_box_one = true;
          std::cout<<"right side pillar is the closest"<<"\n";
        }
        if(PC_2<25){
           is_piller_right = true;
           }
      if(is_piller_right == true && PC_2 <14 && second_piller_right ==false){
        if(PC_2>12.5){
          is_piller_right = false;
          RS_13 ++ ;
          second_piller_right = true;
        } 
      }
      if(is_piller_right == true && PC_2<19 && second_piller_right ==false){
        if(PC_2>17.5){
          is_piller_right = false;
          RS_18 ++;
          second_piller_right = true;
        } 
      }
      if(is_piller_right == true && PC_2 <24 && second_piller_right ==false){
        if(PC_2>22.5){
          is_piller_right = false;
          RS_23 ++ ;
          second_piller_right = true;
        } 
      }
      if(PC_2 == 25){
       is_piller_right = true;
      }
      if(PC_1<25){
           is_piller_left = true;
           }
      if(is_piller_left == true && PC_1 <14 && second_piller_left ==false){
        if(PC_1>12.5){
          is_piller_left = false;
          LS_13 ++ ;
          second_piller_left = true;
        } 
      }
      if(is_piller_left == true && PC_1<19 && second_piller_left ==false){
        if(PC_1>17.5){
          is_piller_left = false;
          LS_18 ++;
          second_piller_left = true;
        } 
      }
      if(is_piller_left == true && PC_1 <24 && second_piller_left ==false){
        if(PC_1>22.5){
          is_piller_left = false;
          LS_23 ++ ;
          second_piller_left = true;
        } 
      }
      if(PC_1 == 25){
       is_piller_left = true;
      }
    }

    //first T juntion
    if( t_jun == true){
        wheels[0]->setVelocity(3);
        wheels[1]->setVelocity(-3);
        second_piller_left = false;
        second_piller_right = false;
        if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6<90 && LF7<90 && LF9>90 && LF8>90 && LF10>90 && LF11<90){
            wheels[0]->setVelocity(3);
            wheels[1]->setVelocity(1);
        }
        if(LF1<90 && LF2<90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11<90){
            wheels[0]->setVelocity(3);
            wheels[1]->setVelocity(1);
        }
        if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11<90){
            wheels[0]->setVelocity(3);
            wheels[1]->setVelocity(1);
        }
        if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6>90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11<90){
            wheels[0]->setVelocity(1);
            wheels[1]->setVelocity(1);
            is_line = false;
            t_jun = false;
            doted_line = true;
               
        }
        
    }

    //starting the doted line code
    if(doted_line== true){
        if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5>90){
          wheels[0]->setVelocity(2.0);
          wheels[1]->setVelocity(2.0);
        }
        if(LF1<90 && LF2<90 && LF4<90 && LF3<90 && LF5>90 && LF8>90 && LF9>90 && LF7>90 && LF6>90){
          wheels[0]->setVelocity(2.0);
          wheels[1]->setVelocity(2.5);
        }
        if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6>90){
          wheels[0]->setVelocity(2.5);
          wheels[1]->setVelocity(2.0);
        }
        if(LF1<90 && LF2>90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6<90 && LF10<90 && LF11<90){
          wheels[0]->setVelocity(2.5);
          wheels[1]->setVelocity(2.0);
        }
        if(LF1<90 && LF2>90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10<90 && LF11<90){
          wheels[0]->setVelocity(2.5);
          wheels[1]->setVelocity(2.0);
        }
        if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10<90 && LF11<90){
          wheels[0]->setVelocity(2.0);
          wheels[1]->setVelocity(3.0);
        }
        if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5>90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10<90 && LF11<90){
          wheels[0]->setVelocity(2.0);
          wheels[1]->setVelocity(3.0);
        }
        if(LF1<90 && LF2<90 && LF4<90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10<90 && LF11<90){
          wheels[0]->setVelocity(2.0);
          wheels[1]->setVelocity(3.0);
        }
      
        if(LF1<90 && LF2<90 && LF3<90 && LF4>90 && LF5>90 && LF6>90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11>90){
          is_dot = true;
        }
        //identifying the dot
        if(is_dot==true){
            if(LF1<90 && LF2<90 && LF3<90 && LF4>90 && LF5>90 && LF6>90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11>90){
               wheels[0]->setVelocity(2.0);
               wheels[1]->setVelocity(4.0);
            }
            if(LF1>90 && LF2>90 && LF3>90 && LF4>90 && LF5>90 && LF6>90 && LF7>90 && LF9>90 && LF8>90 && LF10<90 && LF11>90){
               wheels[0]->setVelocity(2.0);
               wheels[1]->setVelocity(3.0);
            }
            if(LF1>90 && LF2>90 && LF3>90 && LF4>90 && LF5>90 && LF6>90 && LF7>90 && LF9>90 && LF8>90 && LF10>90 && LF11<90){
               wheels[0]->setVelocity(2.0);
               wheels[1]->setVelocity(3.0);
            }
            if(LF1<90 && LF2<90 && LF4>90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7<90 && LF6>90 && LF10<90 && LF11>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
            if(LF1<90 && LF2<90 && LF4>90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7<90 && LF6>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
            if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10<90 && LF11>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
            if(LF1<90 && LF2<90 && LF4>90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
             if(LF1<90 && LF2<90 && LF4>90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
             if(LF1<90 && LF2<90 && LF4>90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
             if(LF1<90 && LF2<90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
             if(LF1>90 && LF2>90 && LF4>90 && LF3>90 && LF5>90 && LF8>90 && LF9>90&& LF7>90 && LF6>90 && LF10>90 && LF11>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
              if(LF1<90 && LF2<90 && LF4>90 && LF3<90 && LF5>90 && LF8>90 && LF9>90&& LF7<90 && LF6>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(3.0);
            }
             if(LF1<90 && LF2>90 && LF4<90 && LF3>90 && LF5<90 && LF8>90 && LF9>90&& LF7>90 && LF6<90 && LF10<90 && LF11>90){
              wheels[0]->setVelocity(4.0);
              wheels[1]->setVelocity(2.0);
            }
            if(LF1<90 && LF2>90 && LF4<90 && LF3>90 && LF5<90 && LF6<90 && LF8<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90){
                exit_doted = true;
                is_line = false ;
                second_box = false;
                doted_line = false;
            }
          }
        }

        //exiting the doted line
         if(exit_doted == true){
            wheels[0]->setVelocity(3);
            wheels[1]->setVelocity(-3);
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF6<90 && LF7<90 &&LF8<90 && LF9>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(2);
              wheels[1]->setVelocity(2);
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF6<90 && LF7<90 &&LF8<90 && LF9<90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(2);
              wheels[1]->setVelocity(2);
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90  && LF5<90 && LF6>90 && LF7>90 &&LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(4);
              wheels[1]->setVelocity(2);
            }
            if(LF1<90 && LF2<90 && LF3>90 && LF4<90  && LF5<90 && LF6<90 && LF7>90 &&LF8>90 && LF9>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(4);
              wheels[1]->setVelocity(2);
            }
           if(LF1<90 && LF2<90 && LF3>90 && LF4<90  && LF5<90 && LF6<90 && LF7>90 &&LF8>90 && LF9>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(4);
              wheels[1]->setVelocity(2);
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90  && LF5<90 && LF6<90 && LF7<90 &&LF8<90 && LF9<90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(4);
              wheels[1]->setVelocity(2);
              exit_doted = false;
              is_line = true;
              t_jun = false;
            }
          }

          // right wall following code
          if(right_WF == true){
            if(WF2>280 && WF1>630){
              if(WF2<310 && WF1<1000){
                wheels[0]->setVelocity(2);
                wheels[1]->setVelocity(2);
              }
            }
            if(WF1 == 1000 && WF2<1000){
              if(WF5<1000 && WF6<1000){
                right_WF = false;
                left_WF = true ;
              }
            }
            // if(WF2<525){
            //   wheels[0]->setVelocity(2.0);
            //   wheels[1]->setVelocity(2.5);
            //   std::cout<<"mwka 1"<<"\n";
            // }
            // if(WF1<925){
            //   wheels[0]->setVelocity(2.0);
            //   wheels[1]->setVelocity(2.5);
            //   std::cout<<"mwka 2"<<"\n";
            // }
            // if(WF2>525){
            //   wheels[0]->setVelocity(2.1);
            //   wheels[1]->setVelocity(2.0);
            //   std::cout<<"mwka 3"<<"\n";
            // }
            // if(WF1>850 && WF5>450){
            //   wheels[0]->setVelocity(2.3);
            //   wheels[1]->setVelocity(2.0);
            //   std::cout<<"meka aul"<<"\n";
            // }
            //  if(WF1<962){
            //   wheels[0]->setVelocity(2.0);
            //   wheels[1]->setVelocity(4.1);
            //   std::cout<<"athana"<<"\n";
            // }
            // if(WF1<720 && WF5<950){
            //   wheels[0]->setVelocity(2.0);
            //   wheels[1]->setVelocity(2.5);
            //   std::cout<<"go"<<"\n";
            // }
            // if(WF1<580 && WF5<740){
            //   wheels[0]->setVelocity(2.0);
            //   wheels[1]->setVelocity(2.5);
            //   std::cout<<"go 1"<<"\n";
            // }

            // if(WF1==1000 && WF2<500 && WF3<700){
            //   wheels[0]->setVelocity(2.0);
            //   wheels[1]->setVelocity(2.2);
            //   std::cout<<"methana"<<"\n";
            // }
            //  if(WF1 == 1000 && WF2==1000 ){
            //   wall_eject = true ;
            //   left_WF = false ;
            //   wheels[0]->setVelocity(2.2);
            //   wheels[1]->setVelocity(2.0);
            //   std::cout<<"wall eject"<<"\n";
            // }
          }

          //left wall following code
          if(left_WF == true){
            if(WF5<525){
              wheels[0]->setVelocity(2.5);
              wheels[1]->setVelocity(2.0);
            }
            if(WF6<925){
              wheels[0]->setVelocity(2.5);
              wheels[1]->setVelocity(2.0);
            }
            if(WF5>525){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.1);
            }
            if(WF6>850 && WF5>450){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.3);
            }
             if(WF6<962){
              wheels[0]->setVelocity(4.1);
              wheels[1]->setVelocity(2.0);
            }
            if(WF6<720 && WF5<950){
              wheels[0]->setVelocity(2.5);
              wheels[1]->setVelocity(2.0);
            }
            if(WF6<580 && WF5<740){
              wheels[0]->setVelocity(2.5);
              wheels[1]->setVelocity(2.0);
            }

            if(WF6==100 && WF5<500 && WF4<700){
              wheels[0]->setVelocity(2.2);
              wheels[1]->setVelocity(2.0);
            }

            if(WF6 == 1000 && WF5==1000 && LF1<90 && LF2<90 && LF3>90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5<90 && LF6>90 && LF8>90){
              wall_eject = true ;
              left_WF = false ;
              wheels[0]->setVelocity(2.2);
              wheels[1]->setVelocity(2.0);
            }
            if(WF6 == 1000 && WF5<1000){
              if(WF2<1000 && WF1<1000){
                right_WF = true;
                left_WF = false; 
              }
            }
          }
          
          //wall ejecting code and line following after that
          if(wall_eject == true){
            second_piller_left = false;
            second_piller_right = false ;
            if(LF1<90 && LF2<90 && LF3>90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5<90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.2);
              wheels[1]->setVelocity(2.0);
            }
            if(LF1<90 && LF2<90 && LF3>90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0);
            }
            if(in_line_2 == false && LF1<90 && LF2<90 && LF3<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(1.0);
              wheels[1]->setVelocity(2.0);
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4>90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.1);
              in_line_2 = true;
            }
            if(in_line_2== true && LF1<90 && LF2<90 && LF3<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.2);
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6>90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.1);
              wheels[1]->setVelocity(2.0);
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.1);
              wheels[1]->setVelocity(2.0);
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8<90 && LF9>90 && LF10<90 && LF11>90){
              turn_right_final = true;
              wall_eject = false;
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF7>90 && LF4<90 && LF5<90 && LF6<90 && LF8<90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0);  
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF7<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90 && LF9<90 && LF10<90 && LF11<90){
              wall_eject = false;
              turn_left_final = true; 
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF7>90 && LF4<90 && LF5<90 && LF6<90 && LF8>90 && LF9>90 && LF10<90 && LF11>90 && front<90){
              wheels[0]->setVelocity(3.0);
              wheels[1]->setVelocity(-3.0);  
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF7<90 && LF4>90 && LF5>90 && LF6>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.1); 
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8<90 && LF9>90 && LF10<90 && LF11>90){
              turn_right_final = true;
              wall_eject = false;
            }
            if(LF1>100 && LF2>100 && LF3>100 && LF4>100 && LF5>100 && LF6>100 && LF7>100 && LF8>100 && LF9>100 && LF10>100 && LF11>100 && end>100){
              if(LF1<300 && LF2<300 && LF3<300 && LF4<300 && LF5<300 && LF6<300 && LF7<300 && LF8<300 && LF9<300 && LF10<300 && LF11<300 && end <300){
                wheels[0]->setVelocity(0.0);
                wheels[1]->setVelocity(0.0);
                Red = true;
                emi_send =  true;
              }
            }
            if(LF1>300 && LF2>300 && LF3>300 && LF4>300 && LF5>300 && LF6>300 && LF7>300 && LF8>300 && LF9>300 && LF10>300 && LF11>300 && end>300 && front>300){
              if(LF1<400 && LF2<400 && LF3<400 && LF4<400 && LF5<400 && LF6<400 && LF7<400 && LF8<400 && LF9<400 && LF10<400 && LF11<400 && end <400 && front<400){
                wheels[0]->setVelocity(0.0);
                wheels[1]->setVelocity(0.0);
                Blue = true;
                emi_send = true;
              }
            }
            //after the second t juntion line foloowing
            if(d_in_line == true){
               if(LF1<90 && LF2<90 && LF3>90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5<90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.2);
            }
            if(LF1<90 && LF2<90 && LF3>90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0);
            }
            if(in_line_2 == false && LF1<90 && LF2<90 && LF3<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(1.0);
              wheels[1]->setVelocity(2.0);
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4>90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.1);
              in_line_2 = true;
            }
            if(in_line_2== true && LF1<90 && LF2<90 && LF3<90 && LF7>90 && LF9>90 && LF10<90 && LF11<90 && LF4<90 && LF5>90 && LF6>90 && LF8>90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.2);
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6>90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.1);
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.2);
            }
            if(LF1<90 && LF2<90  && LF3<90  && LF4>90  && LF5>90 && LF6>90 && LF7<90 && LF9<90 && LF8>90 && LF10<90  && LF11<90 && end<90 && front>90){
              wall_eject = false;
              turn_left_final = true;
            }
          }
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6<90 && LF7<90 && LF8<90 && LF9<90 && LF10<90 && LF11>90){
              wheels[0]->setVelocity(0.0);
              wheels[1]->setVelocity(0.0);
              decision_juntion = true ;
              wall_eject = false;
            }
          }

          //after exiting the wall following taking turns to right
          if(turn_right_final == true){
            wheels[0]->setVelocity(3.0);
            wheels[1]->setVelocity(-3.0);
            if(LF11<90 && LF7<90){
              wheels[0]->setVelocity(3.0);
              wheels[1]->setVelocity(2.0);
            }
             if(LF11<90 && LF7>90 && LF6<90 && LF11<90  && LF8<90){
              wheels[0]->setVelocity(3.0);
              wheels[1]->setVelocity(2.0);
            }
            
            if(jun_eject_1==true && LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8<90 && LF9>90 && LF10<90 && LF11<90 && front<90 && end>90){
              turn_right_final = false;
              wall_eject = true;
              second_piller_left = false;
            }
            if( jun_eject == false && jun_eject_1 == false && LF1<90 && LF2>90 && LF3>90 && LF7>90 && LF4<90 && LF5<90 && LF6<90 && LF8<90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0);  
              turn_right_final = false;
              wall_eject = true;
              second_piller_left = false;
              jun_eject_1 = true ;
              jun_eject_2 = true; 
            }

            if(jun_eject_2==true && LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8<90 && LF9>90 && LF10<90 && LF11<90 && front<90 && end<90){
              turn_right_final = false;
              wall_eject = true;
              second_piller_left = false;
              d_in_line = true;
            }
          
            if(PC_1<25){
              is_piller_left = true;
            }
            if(is_piller_left == true && PC_1 <14 && second_piller_left ==false){
              if(PC_1>12.5){
              is_piller_left = false;
              LS_13 ++ ;
              second_piller_left = true;
              std::cout<<"Pillar at left side-13cm"<<"\n";
              } 
            }
            if(is_piller_left == true && PC_1<19 && second_piller_left ==false){
              if(PC_1>17.5){
                is_piller_left = false;
                LS_18 ++;
                second_piller_left = true;
                std::cout<<"Pillar at left side-18cm"<<"\n";
              } 
            }
            if(is_piller_left == true && PC_1 <25 && second_piller_left ==false){
              if(PC_1>22.5){
                is_piller_left = false;
                LS_23 ++ ;
                second_piller_left = true;
                std::cout<<"Pillar at left side-23cm"<<"\n";
              } 
            }
            if(PC_1 == 25){
              is_piller_left = true;
            }
          }

          //algoritham on the final t juntion
          if(one_time_deci == true && decision_juntion == true){
            if(one_time_m == false){
              LS_13 = LS_13 * 13;
              LS_18 = LS_18 * 18;
              LS_23 = LS_23 * 23;
              RS_13 = RS_13 * 13;
              RS_18 = RS_18 * 18;
              RS_23 = RS_23 * 23;
              LSP = LS_13 + LS_18 + LS_23 ;
              RSP = RS_13 + RS_18 + RS_23 ;
              one_time_m = true ;
              LSP = LSP * 3 ;
              RSP = RSP * 5 ;
              Total = LSP + RSP ;
              D_total = Total % 2;   
            }
            if(D_total == 0){
              even_number = true;
              odd_number = false;
            }
            else{
              even_number = false;
              odd_number = true;
            }
        
            if(even_number == true){
              turn_left_final = true;
            }
            if(odd_number == true){
              turn_right_final = true;
              one_time_deci = false ;
            }
       
          }

          //after exiting the wall following taking next turns to left
          if(turn_left_final == true){
            decision_juntion = false;
            wheels[0]->setVelocity(-3.0);
            wheels[1]->setVelocity(3.0); 
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6>90 && LF7<90 && LF8>90 && LF9>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(3.0);
              wheels[1]->setVelocity(3.0); 
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5<90 && LF6<90 && LF7<90 && LF8>90 && LF9>90 && LF10>90 && LF11<90){
              wheels[0]->setVelocity(3.0);
              wheels[1]->setVelocity(3.0); 
            }
            if(LF1<90 && LF2>90 && LF3>90 && LF4<90 && LF5<90 && LF6>90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              turn_left_final = false ;
              wall_eject = true;
            }
            if(LF1<90 && LF2<90 && LF3>90 && LF4<90 && LF5<90 && LF6<90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0); 
            }
            if(LF1<90 && LF2<90 && LF3>90 && LF4<90 && LF5<90 && LF6>90 && LF7>90 && LF8>90 && LF9>90 && LF10<90 && LF11<90){
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0); 
            }
            if(LF1<90 && LF2<90 && LF3<90 && LF4<90 && LF5>90 && LF6>90 && LF7<90 && LF8>90 && LF9<90 && LF10<90 && LF11<90){
              turn_left_final = false ;
              wall_eject = true;
              wheels[0]->setVelocity(2.0);
              wheels[1]->setVelocity(2.0); 
            }
        
          }

          // after finishing the task sending messages to the reciever robot
          if(emi_send == true){
            if(Blue == true){
              string message(" ");
              message.assign ("blue") ;
              emitter->send(message.c_str(),(int)strlen(message.c_str()) + 1);
            } 
            if(Red == true){
              string message(" ");
              message.assign ("red") ;
              emitter->send(message.c_str(),(int)strlen(message.c_str()) + 1); 
            }
          }
       
  }
}
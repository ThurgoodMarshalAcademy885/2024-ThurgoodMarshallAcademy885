#include <kipr/wombat.h>




int main()
{
    wait_for_light(5); 
    shut_down_in(119);
    enable_servos();
    set_servo_position(1,1222);// position under switch
    int startDistance = 6500; // in ticks 
    int gray = 4000; // between in black and white
    int Afterblacktape = 1000; // in ticks
    int ninetydegreerotation = 1130; //in ticks
    int backupdistance = -400; //in ticks
    int gamecube = 510; //in ticks
    int firstcube = 200; // in ticks
    int secondcube = 420; // in ticks
    int cubebackup = -500; //in ticks
    cmpc(0);
   

    
   
    
    
    
    
    
    // drive from start to before black line
    
    while (gmpc(0) < startDistance)
    {
        mav(0, 1200);
        mav(1, 1200);
    }
    ao() ;

    
   
    
    
    
 
   
    
    // drive to black tape
    
    while (analog(0) < gray)
    {
        mav(0, 1000);
        mav(1, 1000);
    }
    ao() ;

  
    
    
    
    
    
    
    // After black tape to prepare for turn
    cmpc(0);
    while (gmpc(0) < Afterblacktape)
    {
        mav(0, 800);
        mav(1, 800);
    }
    ao() ;
    
    
 
    
    
    
   
    
    // turns towards light switch
     cmpc(0);
        while (gmpc(0) < ninetydegreerotation)
        {
            mav(0, 800);
            mav(1, -800);
        }
        ao();
    
    
     
   
    
    //backup after rotation
    cmpc(0);
        while (gmpc(0) > backupdistance)
        {
            mav(0, -800);
            mav(1, -800);
        }
         ao();
    
    
    
     set_servo_position(1,630); //arms position after rotation
    
  
     msleep(2000);
    
  
    
    
    
    // distance to swicth
    cmpc(0);
         while (digital(9) == 0)
         {
             mav(0,800);
             mav(1,800);
         }
           ao();
    
   
    
    
    
    
    
    msleep(2000);
    
    set_servo_position(1,1222); //position after flipping the switch
    
    
    msleep(1000);
    
    
  
    
    
    
    
    
    
    
    
    //drive to gamecube
     cmpc(0);
         while (gmpc(0) < gamecube)
         {
             mav(0, 400);
             mav(1, 400);
         }
         ao();
    
    msleep(1000);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //first gamecube rotation
    
    cmpc(0);
        while (gmpc(0) < firstcube)
        {
            mav(0, 800);
            mav(1, -800);
        }
        ao();
    
   
  
    
    msleep(1000);
    
    
    
    
    // rotating right for second cube
    
    cmpc(1);
        while (gmpc(1) < secondcube)
        {
            mav(0, -750);
            mav(1, 750);
        }
        ao();
    
    
    
   
    
  
    
      // backup distance after hitting cubes
    msleep(500);
    
    cmpc(0);
        while (gmpc(0) > cubebackup)
        {
            mav(0, -800);
            mav(1, -800);
        }
         ao();
   


  
    
    
    
    
    
    return 0;
}

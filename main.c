#include <kipr/wombat.h>

int main()
{
    //Connects to create3 bot
    create3_connect(); 


    //Wait for light before start 
    wait_for_light(0);
    shut_down_in(119);


    //Drive foward directly infront of the Black Line
    create3_drive_straight (0.94, 20);


    //Rotate left to allign perpindicular black line
    create3_rotate_degrees (90, 30);


    //Dump Button on the side of gameboard
    {
        while (digital (0) == (0))
        {
            create3_drive_straight (-0.0015, 0.07);

        }

    }


    // Drive foward and rotate under the tube
    create3_drive_straight (0.06, 0.06);
    create3_rotate_degrees (-90, 30);
    create3_wait();

    msleep(1000);


    //Wiggle 
    create3_rotate_degrees (5, 46);
    create3_rotate_degrees (-5, 46);
    create3_rotate_degrees (5, 46);
    create3_rotate_degrees (-5, 46);
    create3_rotate_degrees (5, 46);
    create3_rotate_degrees (-5, 46);
    create3_rotate_degrees (5, 46);
    create3_rotate_degrees (-5, 46);

    msleep(500);


    //Drive to Lava station
    create3_drive_straight (0.30, 30);
    create3_rotate_degrees (90, 30);
    create3_rotate_degrees (-90, 30);
    msleep(500);
    create3_drive_straight (0.40, 30);

    create3_wait();      
    return 0;
}

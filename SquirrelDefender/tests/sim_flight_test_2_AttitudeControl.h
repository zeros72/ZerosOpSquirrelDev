#include "standard_libs.h"
#include "mavlink_msg_handler.h"
#include "mavlink_command_handler.h"
#include "attitude_controller.h"

extern int32_t alt;

const float dt = 0.025;
const float error_cal = 0.1;

float timerVal = 0;
int stage = 0;

void countupTimer(void)
{
    timerVal = timerVal + dt; // printf("Timer: %.3f\n", timerVal);
}

void resetTimer(void)
{
    timerVal = 0;
}

void test_flight(void)
{
    countupTimer();

    if (alt > 5.0 && stage == 0)
    {
        move_forward();
        stage = 1;
    }

    // if (timerVal > 8 && stage == 1)
    // {
    //     brake();
    //     stage = 2;
    //     //landing_sequence();
    // }

    /*if (timerVal > 14.0)
    {
        landing_sequence();
    }*/
}
#include "standard_libs.h"
#include "mavlink_msg_handler.h"
#include "mavlink_command_handler.h"

const float dt = 0.025;

float timerVal = 0;
int stage = 0;
int32_t A_lat = -353630743;
int32_t A_lon = 1491646454;
float A_alt = 5;
int32_t B_lat = -353638947;
int32_t B_lon = 1491648283;
float B_alt = 6;
int32_t C_lat = -353637206;
int32_t C_lon = 1491660477;
float C_alt = 5;

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
    if (stage <= 3)
    {
        countupTimer();
    }

    if (timerVal > 10.0 && stage == 0)
    {
        printf("Moving to A\n");
        stage = stage + 1;
        resetTimer();
        go_to_waypoint(A_lat, A_lon, A_alt);

    }

    if (timerVal > 10.0 && stage == 1)
    {
        printf("Moving to B\n");
        stage = stage + 1;
        resetTimer();
        go_to_waypoint(B_lat, B_lon, B_alt);
    }

    if (timerVal > 10.0 && stage == 2)
    {
        printf("Moving to C\n");
        stage = stage + 1;
        resetTimer();
        go_to_waypoint(C_lat, C_lon, C_alt);
    }

    if (timerVal > 10.0 && stage == 3)
    {
        printf("Returning to base\n");
        stage = stage + 1;
        resetTimer();
        landing_sequence();
    }
}

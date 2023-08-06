#include "TrafficLight.h"
#include <iostream>

void
TrafficLight::SwitchOn()
{
    lightState = true;
}

void
TrafficLight::SwitchOff()
{
    lightState = false;
}

bool TrafficLight::getLightState()
{
    return lightState;
}
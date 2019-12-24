#include "./PWM_Changer.h"

PWMChanger::PWMChanger() 
{
    
}

/**
 * Getters for the the variables used in this class
**/
int PWMChanger::getMinPWM()
{
    return this->minPWM;
}

int PWMChanger::getMaxPWM()
{
    return this->maxPWM;
}

float PWMChanger::getCurrentPWM()
{
    return this->currentPWM;
}

int PWMChanger::getTarget()
{
    return this->target;
}

/**
 * Setters for the variables used in this class
**/
void PWMChanger::setMinPWM(int minPWM)
{
    this->minPWM = minPWM;
}

void PWMChanger::setMaxPWM(int maxPWM)
{
    this->maxPWM = maxPWM;
}

void PWMChanger::setCurrentPWM(float currentPWM)
{
    this->currentPWM = currentPWM;
}

void PWMChanger::setTarget(int target)
{
    this->target = target;
}

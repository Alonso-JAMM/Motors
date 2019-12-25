#include "PWM_Changer.h"
#include <cmath>

PWMChanger::PWMChanger(const int type):
linFunction(&tick)
{
    // setting up the function used to change the PWM
    this->functionType = type;
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

int PWMChanger::getTick()
{
    return this->tick;
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
    this->target = targetLimiter(target);
}


void PWMChanger::setTick(int tick)
{
    this->tick = tick;
}


/*
 * makes Sure that the new target is withing the limits defined by minPWM and 
 * maxPWM
 */
int PWMChanger::targetLimiter(int target)
{
    if (target < minPWM)
    {
        return minPWM;
    }
    else if (target > maxPWM)
    {
        return maxPWM;
    }
    else
    {
        return target;
    }
}

/*
 * returns true if newPWM is too close to the target
 */
bool PWMChanger::isNewPWMClose(float newPWM)
{
//     float change = newPWM - currentPWM;
//     if (std::abs(target - currentPWM) < std::abs(newPWM - currentPWM))
    if (((currentPWM < newPWM) && (target < newPWM))
        || (currentPWM > newPWM) && (target > newPWM))
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
 * Increaes the value of currentPWM depending on the type of the function
 */
void PWMChanger::increasePWM()
{
    float newPWM = 0;
    
    // Linear function
    if (functionType == 0)
    {        
        newPWM = linFunction.increase(currentPWM);
    }
    
    // Now we check if the new PWM is too close to the target
    // if it is too close, then we set currentPWM to target
    if (isNewPWMClose(newPWM))
    {
        currentPWM = target;
        tick = 0;   // Reset ticks
    }
    else
    {
        currentPWM = newPWM;
        tick++;
    }
}

/*
 * Decreases the value of current PWM depending on the type of function
 */
void PWMChanger::decreasePWM()
{
    float newPWM = 0;
    
    // Linear functions
    if (functionType == 0)
    {
        newPWM = linFunction.decrease(currentPWM);
    }
    
    if (isNewPWMClose(newPWM))
    {
        currentPWM = target;
        tick = 0;
    }
    else
    {
        currentPWM = newPWM;
        tick++;
    }
}

/* 
 * Gets a new PWM value towards target 
 */
void PWMChanger::update()
{

    if (currentPWM < target)
    {
        increasePWM();

    }
    else if (currentPWM > target)
    {
        decreasePWM();
    }
   
   // Just to make sure that we set ticks to zero when PWM reaches the target
   if (currentPWM == target)
    {
        tick = 0;
    }
}

#include "PWM_Changer.h"

PWMChanger::PWMChanger(const int type):
linFunction(&tick),
expFunction(&tick)
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
    if (currentPWM >= lowSkip && currentPWM <= highSkip)
    {
        return 0;
    }
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

int PWMChanger::getLowSkip()
{
    return this->lowSkip;
}

int PWMChanger::getHighSkip()
{
    return this->highSkip;
}

int PWMChanger::getFunctionType()
{
    return this->functionType;
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
    // ticks reseted when new target is set
    this->tick = 0;
}

void PWMChanger::setTick(int tick)
{
    this->tick = tick;
}

void PWMChanger::setLowSkip(int lowSkip)
{
    this->lowSkip = lowSkip;
}

void PWMChanger::setHighSkip(int highSkip)
{
    this->highSkip = highSkip;
}

void PWMChanger::setFunctionType(int newFuntionType)
{
    this->functionType = newFuntionType;
}


/*
 * makes Sure that the new target is withing the limits defined by minPWM and 
 * maxPWM
 */
int PWMChanger::targetLimiter(int target)
{
    int newTarget;
    // maximum limitters
    if (target < minPWM)
    {
        newTarget = minPWM;
    }
    else if (target > maxPWM)
    {
        newTarget = maxPWM;
    }
    else
    {
        newTarget = target;
    }
    
    // skip region limitters
    // we don't want target inside the skip region
    if ((target > lowSkip) && (target < highSkip))
    {
        newTarget = lowSkip;
    }
    
    return newTarget;
}

/*
 * Skips over the skip region (unwanted region where PWM is too close to "OFF")
 * Note that this function only works with currentPWM
 */
void PWMChanger::skipRegion()
{
    if ((currentPWM > lowSkip) && (currentPWM < highSkip))
    {
        // Decreasing PWM
        if (target < currentPWM)
        {
            currentPWM = lowSkip;
        }
        else 
        {
            currentPWM = highSkip;
        }
        // Now we set up functions 
        // the vertical shift changes
        if (functionType == 0)
        {
            linFunction.setB(currentPWM);
        }
        else if (functionType == 1)
        {
            expFunction.setD(currentPWM);
        }
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
    else if (functionType == 1)
    {
        newPWM = expFunction.increase(currentPWM);
    }
    
    // check if the new PWM is too close to the target
    // if it is too close, then we set currentPWM to target
    if (isNewPWMClose(newPWM))
    {
        currentPWM = target;
    }
    else
    {
        currentPWM = newPWM;
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
    else if (functionType == 1)
    {
        newPWM = expFunction.decrease(currentPWM);
    }
    
    if (isNewPWMClose(newPWM))
    {
        currentPWM = target;
    }
    else
    {
        currentPWM = newPWM;
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
    
    skipRegion();
    //std::cout << "    " << currentPWM << " " << tick << std::endl;
    
    // new tick after each iteration is run (until new target is set)
    tick++;
}

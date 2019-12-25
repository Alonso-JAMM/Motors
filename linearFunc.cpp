#include "linearFunc.h"

LinearF::LinearF(int *x)
{
    this->x = x;
}

LinearF::LinearF(float a, float b, int *x)
{
    this->a = a;
    this->b = b;
    this->x = x;
}


/*
 * Getters for the variables 
 */
float LinearF::getA()
{
    return this->a;
}

float LinearF::getB()
{
    return this->b;
}

/*
 * Setters for the variables
 */

void LinearF::setA(float a)
{
    this->a = a;
}

void LinearF::setB(float b)
{
    this->b = b;
}

/*
 * we get a new PWM value by calling this function (The new PWM is an increase
 * from the old PWM)
 */
float LinearF::increase(float currentPWM)
{
    if (a < 0)
    {
        a = -a; // we want to increase the PWM value!
    }
    if (*x == 0)
    {
        b = currentPWM;
    }
        
    return a*(*x) + b;
}


/*
 * we get a new PWM value by calling this functions (new PWM is an decrease 
 * from the old PWM)
 */
float LinearF::decrease(float currentPWM)
{
    if (a > 0)
    {
        a = -a; // we want to decrease the PWM value!
    }
    if (*x == 0)
    {
        b = currentPWM;
    }
    
    return a*(*x) + b;
}

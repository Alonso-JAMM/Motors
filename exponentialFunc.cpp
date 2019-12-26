#include "exponentialFunc.h"
#include <math.h>

ExpF::ExpF(int* x)
{
    this->x = x;
}

/*
 * Getters for the variables
 */
float ExpF::getA()
{
    return a;
}

float ExpF::getB()
{
    return b;
}

float ExpF::getC()
{
    return c;
}

float ExpF::getD()
{
    return d;
}

/*
 * Setters for the variables
 */
void ExpF::setA(float a)
{
    this->a = a;
}

void ExpF::setB(float b)
{
    this->b = b;
}

void ExpF::setC(float c) 
{
    this->c = c;
}

void ExpF::setD(float d)
{
    this->d = d - a*exp(b*(*x)-c);
}

/*
 * Get a new PWM value by valling this function (new PWM is a decrease from the
 * previous PWM)
 */
float ExpF::decrease(float currentPWM)
{
    if (a > 0)
    {
        a = -a;
    }
    if (*x == 0)
    {
        d = currentPWM - a*exp(-c);
    }
    
    return a*exp(b*(*x) - c) + d;
}

/*
 * Get a new PWM value by caling this function (new PWM is an increase from the 
 * previous PWM)
 */
float ExpF::increase(float currentPWM)
{
    if (a < 0)
    {
        a = -a;
    }
    if (*x == 0)
    {
        d = currentPWM - a*exp(-c);
    }
    
    return a*exp(b*(*x) - c) + d;
}

/*
 * Get x value to corresponding function output
 */
float ExpF::calculateX(float y)
{
    return (1/b)*log((1/a)*(y - d)) + c;
}

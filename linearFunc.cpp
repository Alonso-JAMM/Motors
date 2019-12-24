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

#ifndef LINEARFUNC_h
#define LINEARFUNC_h

/*
 * Class representing a linear function of the form: ax+b 
 * where a, b are constants that modify the function,
 * and x is a "tick" (the independent variable)
 * 
 */

class LinearF
{
private:
    // variables
    float a = 5;
    float b = 0;
    int* x;     // Points to the tick of instance of PWMChanger class
public:
    LinearF();
    LinearF(int*);
    LinearF(float, float, int*);
    // getters and setters of variables
    float getA();
    float getB();
    void setA(float);
    void setB(float);
    // calculates new PWM value when we want to increase or decrease the PWM
    float increase(float);
    float decrease(float);
};



#endif

#ifndef EXPONENTIALFUNC_h
#define EXPONENTIALFUNC_h

/*
 * Class that represents an exponential function of the form: a*e^(bx - c) + d
 * where a,b,c,d are constants and x is a "tick" (the independent variable)
 */
class ExpF
{
private:
    // variables
    float a = 50;
    float b = 0.03;
    float c = 0;
    float d = 0;
    int* x;     // Points to the tick of the instance of PWMChanger class
public:
    ExpF(int*);
    // getters and seters of variables
    float getA();
    float getB();
    float getC();
    float getD();
    void setA(float);
    void setB(float);
    void setC(float);
    void setD(float);
    // calculates new PWM value when we want to increase or decrease the PWM 
    float increase(float);
    float decrease(float);
    float calculateX(float);
};


#endif

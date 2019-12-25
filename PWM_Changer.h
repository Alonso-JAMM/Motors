#ifndef PWM_Changer_h
#define PWM_Changer_h
#include "linearFunc.h"
//#include "functions.h"


/*
 * There can be many different PWM changing functions so each one will be
 * represented by a number:
 *
 *  0 - Linear Function: It will change the PWM in a linear manner 
 */


class PWMChanger 
{
private:
    // variables
    float minPWM = -255;
    float maxPWM = 255;
    float currentPWM = 0.0;
    float target = 0;
    int tick = 0;
    int funcType;
    int functionType;
    void increasePWM();
    void decreasePWM();
    bool isNewPWMClose(float);
public:
    PWMChanger(const int type = 0); // Constructor
    // getters and setters for the variables
    int getMinPWM();
    int getMaxPWM();
    float getCurrentPWM();
    int getTarget();
    int getFuncType();
    int getTick();
    void setMinPWM(int);
    void setMaxPWM(int);
    void setCurrentPWM(float);
    void setTarget(int);
    void setTick(int);
    int targetLimiter(int);
    // gets new PWM
    void update();
    
    // Speed changing functions
    // Note that the user may need to change the constant values of the function
    LinearF linFunction;    // Linear function
};




#endif

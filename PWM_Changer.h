#ifndef PWM_Changer_h
#define PWM_Changer_h
#include "linearFunc.h"
#include "exponentialFunc.h"


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
    int minPWM = -255;
    int maxPWM = 255;
    float currentPWM = 0.0;
    int target = 0;
    int lowSkip = -30;
    int highSkip = 30;
    int tick = 0;
    int funcType;
    int functionType;
    void increasePWM();
    void decreasePWM();
    bool isNewPWMClose(float);
    void skipRegion();
public:
    PWMChanger(const int type = 0); // Constructor
    // getters and setters for the variables
    int getMinPWM();
    int getMaxPWM();
    float getCurrentPWM();
    int getTarget();
    int getFuncType();
    int getTick();
    int getLowSkip();
    int getHighSkip();
    void setMinPWM(int);
    void setMaxPWM(int);
    void setCurrentPWM(float);
    void setTarget(int);
    void setTick(int);
    void setLowSkip(int);
    void setHighSkip(int);
    int targetLimiter(int);
    // gets new PWM
    void update();
    
    // Speed changing functions
    // Note that the user may need to change the constant values of the function
    LinearF linFunction;    // Linear function
    ExpF expFunction;       // Exponential function
};




#endif

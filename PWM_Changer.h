#ifndef PWM_Changer_h
#define PWM_Changer_h
#include "linearFunc.h"

class PWMChanger 
{
private:
    // variables
    int minPWM = 0;
    int maxPWM = 0;
    float currentPWM = 0.0;
    int target = 0;
    int tick = 0;
public:
    PWMChanger(); // Constructor
    // getters and setters for the variables
    int getMinPWM();
    int getMaxPWM();
    float getCurrentPWM();
    int getTarget();
    void setMinPWM(int);
    void setMaxPWM(int);
    void setCurrentPWM(float);
    void setTarget(int);
    void setTick(int);
    void update(); 
    // Speed changing functions
    // Note that the user may need to change the constant values of the function
    LinearF linFunction;    // Linear function
};




#endif

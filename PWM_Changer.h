#ifndef PWM_Changer_h
#define PWM_Changer_h


class PWMChanger 
{
private:
    // variables
    int minPWM = 0;
    int maxPWM = 0;
    float currentPWM = 0.0;
    int target = 0;
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
};




#endif

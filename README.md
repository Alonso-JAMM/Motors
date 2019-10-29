# Introduction

I began working on this code with the purpose of changing the speed of a motor or the 
brightness of LEDs exponentially.

The reason of wanting to change the PWM exponentially is due to using a keyboard to 
control an Arduino. With a keyboard there could be only be two states (on or off) when
pressing keys. However, I wanted change the PWM as time passes while the key is pressed. It 
is easier to use a linear change in PWM over time, but I found that it does not "feel right." 
A linear change of PWM is good enough for changing the speed of a motor. Though, it is not 
enough for changing the brightness of the LEDs. I think that exponential change in PWM would 
better suited to change the brightness of LEDs since often I want to make small changes in 
the brightness of the LED if the key is pressed momentarily. But if the key pressed is
longer I would like increase the PWM faster. That is, slow rate of change at first and 
increase said rate of change as time passes.

So I though about a graph that looked more or less like this:
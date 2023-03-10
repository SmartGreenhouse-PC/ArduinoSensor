#ifndef __FAN__
#define __FAN__

#include "Ventilation.h"
#include "Arduino.h"

/**
 * Implementation of a Ventilation class representing a Fan device.
*/
class Fan: public Ventilation
{
    public:
        Fan(int enablePin, int diraPin, int dirbPin);
        void activate();
        void deactivate();
        bool isActive();

    private:
        int enablePin;
        int diraPin;
        int dirbPin;
        bool active;
};

#endif
#ifndef __CLUDACTHOLD__
#define __CLUDACTHOLD__

#include "Arduino.h"

/**
 * Declaration of the class CloudActuatorSystemHolder.
*/
class CloudActuatorSystemHolder
{
    int* luminositySystem;
    bool* temperatureSystem;
    bool* irrigationSystem;
    bool* ventilationSystem;

    public:
        /**
         * Constructor of the class.
         * @param luminositySystem the actuator related to the luminosity.
         * @param temperatureSystem the actuator related to the temperature.
         * @param irrigationSystem the actuator related to the soil moisture.
         * @param ventilationSystem the actuator related to the humidity.
        */
        CloudActuatorSystemHolder(int* luminositySystem, bool* temperatureSystem, bool* irrigationSystem, bool* ventilationSystem);
        /**
         * Update the cloud parameter related to the luminosity.
         * @param state, the current state of the actuator.
        */
        void updateLuminositySystem(int state);
        /**
         * Update the cloud parameter related to the temperature.
         * @param state, the current state of the actuator.
        */
        void updateTemperatureSystem(String state);
        /**
         * Update the cloud parameter related to the soil moisture.
         * @param state, the current state of the actuator.
        */
        void updateIrrigationSystem(String state);
        /**
         * Update the cloud parameter related to the humidity.
         * @param state, the current state of the actuator.
        */
        void updateVentilationSystem(String state);
};

#endif
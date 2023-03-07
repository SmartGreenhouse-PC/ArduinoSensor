#ifndef __CLOUDMANAGER__
#define __CLOUDMANAGER__

#include "CloudActuatorSystemHolder.h"
#include "CloudParameterHolder.h"
#include "Arduino.h"
#include <ArduinoJson.h>

/**
 * Declaration of the class CloudVariableManager
*/
class CloudVariableManager
{
    CloudActuatorSystemHolder* actuatorHolder;
    CloudParameterHolder* parameterHolder;

    public:
        /**
         * Constructor of the class.
         * @param actuatorHolder the holder of the actuators.
         * @param parameterHolder the holder of the parameter values.
        */
        CloudVariableManager(CloudActuatorSystemHolder* actuatorHolder, CloudParameterHolder* parameterHolder);
        /**
         * Handle the message to update the parameter values.
         * @param msg, the message received
        */
        void manageCloudParameterUpdate(String msg);
        /**
         * Handle the message to update the actuators status.
         * @param topic, the topic of the message received.
         * @param action, the action to perform.
        */
        void manageActuatorUpdate(String topic, String action);
};

#endif
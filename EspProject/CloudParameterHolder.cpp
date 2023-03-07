#include "CloudParameterHolder.h"

/**
 * Implementation of the class CloudParameterHolder.
*/
CloudParameterHolder::CloudParameterHolder(float* brightness, float* temperature, float* humidity,  float* soilMoisture)
{
    this->brightness = brightness;
    this->temperature = temperature;
    this->humidity = humidity;
    this->soilMoisture = soilMoisture;
}

void CloudParameterHolder::updateBrightness(float newValue){
    *brightness = newValue;
}

void CloudParameterHolder::updateTemperature(float newValue){
    *temperature = newValue;
}

void CloudParameterHolder::updateHumidity(float newValue){
    *humidity = newValue;
}

void CloudParameterHolder::updateSoilMoisture(float newValue){
    *soilMoisture = newValue;
}


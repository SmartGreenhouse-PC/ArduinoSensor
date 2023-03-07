#ifndef __CLUDPARHOLD__
#define __CLUDPARHOLD__

/** 
 * Declaration of the class CloudParameterHolder.
*/
class CloudParameterHolder
{
    float* brightness;
    float* temperature;
    float* humidity;
    float* soilMoisture;

  public:
    /**
     * Constructor of the class.
     * @param brightness the brightness value.
     * @param temperature the temperature value.
     * @param humidity the humidity value.
     * @param soilMoisture the soil moisture value.
    */
    CloudParameterHolder( float* brightness, float* temperature, float* humidity,  float* soilMoisture);
    /**
     * Update the brightness value.
     * @param newValue the new brightness value.
    */
    void updateBrightness(float newValue);
    /**
     * Update the temperature value.
     * @param newValue the new brightness value.
    */
    void updateTemperature(float newValue);
    /**
     * Update the humidity value.
     * @param newValue the new brightness value.
    */
    void updateHumidity(float newValue);
    /**
     * Update the soil moisture value.
     * @param newValue the new brightness value.
    */
    void updateSoilMoisture(float newValue);
};

#endif
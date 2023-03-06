#ifndef __CLUDPARHOLD__
#define __CLUDPARHOLD__

class CloudParameterHolder
{
    float* brightness;
    float* temperature;
    float* humidity;
    float* soilMoisture;

  public:
      CloudParameterHolder( float* brightness, float* temperature, float* humidity,  float* soilMoisture);
      void updateBrightness(float newValue);
      void updateTemperature(float newValue);
      void updateHumidity(float newValue);
      void updateSoilMoisture(float newValue);
};

#endif
#include "CloudVariableManager.h"

/**
 * Implementation of the class CloudVariableManager.
*/
CloudVariableManager::CloudVariableManager(CloudActuatorSystemHolder* actuatorHolder, CloudParameterHolder* parameterHolder)
{
    this->actuatorHolder = actuatorHolder;
    this->parameterHolder = parameterHolder;
}

void CloudVariableManager::manageCloudParameterUpdate(String msg){
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, msg.c_str());
  String param = doc["param"];
  float value = doc["value"];

  if(param.equals("Bright"))
  {
    this->parameterHolder->updateBrightness(value);
  }
  else if(param.equals("Temp"))
  {
    this->parameterHolder->updateTemperature(value);
  }
  else if(param.equals("Soil"))
  {
    this->parameterHolder->updateSoilMoisture(value);
  }
  else if(param.equals("Hum"))
  {
    this->parameterHolder->updateHumidity(value);
  }
}

void CloudVariableManager::manageActuatorUpdate(String topic, String action){
  if(topic.equals("LUMINOSITY"))
  {
    this->actuatorHolder->updateLuminositySystem(action.toInt());
  }
  else if(topic.equals("TEMPERATURE"))
  {
    this->actuatorHolder->updateTemperatureSystem(action);
  }
  else if(topic.equals("IRRIGATION"))
  {
    this->actuatorHolder->updateIrrigationSystem(action);
  }
  else if(topic.equals("VENTILATION"))
  {
    this->actuatorHolder->updateVentilationSystem(action);
  }
}

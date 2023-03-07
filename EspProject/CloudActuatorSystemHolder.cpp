#include "CloudActuatorSystemHolder.h"

/** 
 * Implementation of the class CloudActuatorSystemHolder.
*/
CloudActuatorSystemHolder::CloudActuatorSystemHolder(int* luminositySystem, bool* temperatureSystem, bool* irrigationSystem, bool* ventilationSystem)
{
    this->luminositySystem = luminositySystem;
    this->temperatureSystem = temperatureSystem;
    this->irrigationSystem = irrigationSystem;
    this->ventilationSystem = ventilationSystem;
}

void CloudActuatorSystemHolder::updateLuminositySystem(int state)
{
    *luminositySystem = state;
}

void CloudActuatorSystemHolder::updateTemperatureSystem(String state)
{
  if(state.equals("increase") || state.equals("decrease"))
  {
    *temperatureSystem = true;
  }else if(state.equals("turn-off")){
    *temperatureSystem = false;
  }
}

void CloudActuatorSystemHolder::updateIrrigationSystem(String state)
{
  if(state.equals("on")){
    *irrigationSystem = true;
  }else if(state.equals("off"))
  {
    *irrigationSystem = false;
  }
}

void CloudActuatorSystemHolder::updateVentilationSystem(String state)
{
  if(state.equals("on")){
    *ventilationSystem = true;
  }else if(state.equals("off"))
  {
    *ventilationSystem = false;
  }
}
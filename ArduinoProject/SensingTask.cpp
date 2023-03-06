#include "SensingTask.h"

/**
 * Implementation of the class SensingTask.
*/
SensingTask::SensingTask(Brightness *photoresistor, SoilMoistureSensor *soilMoistureSensor, Temperature *temp, Humidity *hum, Sender *sender, String greenhouseId)
{
    this->photoresistor = photoresistor;
    this->soilMoistureSensor = soilMoistureSensor;
    this->temp = temp;
    this->hum = hum;
    this->active = false;
    
    this->temperatureValue = 0.0;
    this->humidityValue = 0.0;
    this->brightnessValue = 0.0;
    this->soilMoistureValue = 0.0;

    this->sender = sender;

    this->greenhouseId = greenhouseId;
}


void SensingTask::init(unsigned long period)
{
    Task::init(period);
}

void SensingTask::setActive(bool active)
{
    this->active = active;
}

bool SensingTask::isActive()
{
    return this->active;
}

void SensingTask::tick()
{

    temperatureValue = this->temp->getTemperature();
    humidityValue = this->hum->getHumidity();
    brightnessValue = this->photoresistor->getBrightness();
    soilMoistureValue = this->soilMoistureSensor->getValue();

    this->sendMessage("Temp", String(temperatureValue));
    this->sendMessage("Hum", String(humidityValue));
    this->sendMessage("Bright", String(brightnessValue));
    this->sendMessage("Soil", String(soilMoistureValue));
}

void SensingTask::sendMessage(String parameter, String value){
    String msg = "{'id': '" + this->greenhouseId + "','param': '" + parameter + "','value': " + value+ "}";
    sender->notifyMsg(msg);
    msg = "";
    delay(1000);
}

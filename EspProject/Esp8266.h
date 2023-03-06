#ifndef __ESP__
#define __ESP__

#define IRRIGATION "IRRIGATION"
#define LUMINOSITY "LUMINOSITY"
#define TEMPERATURE "TEMPERATURE"
#define VENTILATION "VENTILATION"

#include "Arduino.h"
#include "Connection.h"
#include "CloudParameterHolder.h"
#include "MsgServiceArduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

/**
 * A class representing an ESP8266 WiFi module.
*/
class Esp8266: public Connection { 
    char* ssidName;
    char* pwd; 
    WiFiClient espClient;
    PubSubClient client;
    CloudParameterHolder *holder;
    public:
        /**
         * Constructor of Esp8266 object.
         * @param ssidName The SSID of the WiFi network.
         * @param pwd The password of the WiFi network.
         * @param mqttServer The address of the MQTT broker.
         * @param msgARD A pointer to a MsgServiceArduino object.
         * @param greenhouseId Greenhouse identification.
         */
        Esp8266(char *ssidName, char *pwd, char *mqttServer, MsgServiceArduino *msgARD, CloudParameterHolder *holder, String greenhouseId);
        void connecting();
        void sendData(char* topic, String msg);
        void processIncomingMessages();
        bool isConnected(); 
        MsgServiceArduino *msgARD;
    private:
        String greenhouseId;
        void callback(char *topic, byte *payload, unsigned int length);
        void reconnect();
        void manageCloudParameterUpdate(String msg);
};

#endif

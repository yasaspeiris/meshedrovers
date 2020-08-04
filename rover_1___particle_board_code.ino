#include <Wire.h>
int node = -1;
int prev_node = -1;

#include "Adafruit_DHT.h"
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22		// DHT 22 (AM2302)


DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Wire.begin(9); 
    Wire.onReceive(receiveEvent); // Attach a function to trigger when something is received.
	dht.begin();
	
	
}

void receiveEvent(int bytes) {
    node = Wire.read();    // read one character from the I2C
}

void loop() {
    
    if (node!=prev_node){
      t = dht.getTempCelcius();
	    
	    Particle.publish("node1", String(node) , 60, PUBLIC);
	    char eventData[10];
      sprintf(eventData, "%.2f", t);
      Particle.publish("temperature", eventData, 60, PUBLIC);
	
	    prev_node = node;
	
    }
    

}

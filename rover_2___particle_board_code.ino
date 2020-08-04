#include <Wire.h>
int node = -1;
int prev_node = -1;

byte started = 0;


void setup() {
    Wire.begin(9); 
    Wire.onReceive(receiveEvent); // Attach a function to trigger when something is received.
}

void receiveEvent(int bytes) {
    node = Wire.read();    // read one character from the I2C
}


void loop() {
    
    
    if (node!=prev_node){
        int g = analogRead(A5);
	    
	    Particle.publish("node2", String(node) , 60, PRIVATE);
        Particle.publish("gas", String(g), 60, PRIVATE);
	
	    prev_node = node;
	
    }
    

}

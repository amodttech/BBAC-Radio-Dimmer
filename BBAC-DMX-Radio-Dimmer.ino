#include <Conceptinetics.h>
#define DMX_SLAVE_CHANNELS   10 
DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS);

const int ledPin = 9;

void setup() {
  dmx_slave.enable();  
  dmx_slave.setStartAddress(450);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int dmxBrightness = dmx_slave.getChannelValue(1);
  analogWrite(ledPin, dmxBrightness);
  }
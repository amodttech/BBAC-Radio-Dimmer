// Include library for DMX Shield
#include <Conceptinetics.h>

// The slave device will use a block of 10 channels, counting from its start address.
#define DMX_SLAVE_CHANNELS   10 
// Configure a DMX slave controller
DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS);

// Using pin 9 for PWM, required for dimming
int ledPin = 9;

void setup() {
    // Enable DMX slave and start recording DMX data
    dmx_slave.enable();
    // Set starting address
    dmx_slave.setStartAddress(450);
    // Set ledPin as an OUTPUT pin
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Create brightness variable that is defined as the DMX signal value
    int dmxBrightness = dmx_slave.getChannelValue(1);
    // Output brightness level to the LED.
    analogWrite(ledPin, dmxBrightness);
  }
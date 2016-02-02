#include <user_config.h>
#include <SmingCore/SmingCore.h>

#define LED_PIN 12 // GPIO12 (D6)

DriverPWM ledPWM;
Timer procTimer;

void loop();


void init() {
	// Set GPIO mode
	pinMode(LED_PIN, OUTPUT);
	// initialize PWM
	ledPWM.initialize();
	// Setup serial
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(true); // Enable debug output to serial
	// Start arduino style loop
	procTimer.initializeMs(50, loop).start();
}

void loop() {
	int brightness = system_adc_read(); // Replace analogRead(ANALOG_PIN) of arduino
	if(brightness > 1000) brightness = 1000;
	else if(brightness < 0) brightness = 0;
	ledPWM.analogWrite(LED_PIN, brightness/10);
}

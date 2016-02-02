#include <user_config.h>
#include <SmingCore/SmingCore.h>

#define BUTTON_PIN 14 // GPIO14 (D5)
#define LED_PIN 12 // GPIO12 (D6)

Timer procTimer;
void loop();

void init() {
	// Set GPIO mode
	pinMode(BUTTON_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
	// Setup serial
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(true); // Enable debug output to serial
	// Start arduino style loop
	procTimer.initializeMs(50, loop).start();
}

void loop() {
	bool isPressed = digitalRead(BUTTON_PIN);
	if(isPressed)
		digitalWrite(LED_PIN, HIGH);
	else
		digitalWrite(LED_PIN, LOW);
}

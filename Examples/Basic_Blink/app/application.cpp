#include <user_config.h>
#include <SmingCore/SmingCore.h>

#define LED_PIN 12 // GPIO12 (D6)

Timer procTimer;
bool state = true;

void loop()
{
	digitalWrite(LED_PIN, state);
	state = !state;
}

void init()
{
	pinMode(LED_PIN, OUTPUT);
	procTimer.initializeMs(1000, loop).start();
}

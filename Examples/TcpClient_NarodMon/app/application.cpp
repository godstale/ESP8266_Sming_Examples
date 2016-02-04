/* TCP client example
 * By JustACat http://esp8266.ru/forum/members/120/
 * 23.04.2015
 */
#include <user_config.h>
#include <SmingCore/SmingCore.h>

// If you want, you can define WiFi settings globally in Eclipse Environment Variables
#ifndef WIFI_SSID
	#define WIFI_SSID "PleaseEnterSSID" // Put you SSID and Password here
	#define WIFI_PWD "PleaseEnterPass"
#endif

#define REMOTE_HOST "your_host.com"
#define REMOTE_PORT 8283


Timer procTimer; // TCP timer
String mac;
float t1 = -2.5; // sensor value

void onCompleted(TcpClient& client, bool successful)
{
	// debug msg
	debugf("onCompleted");
	debugf("successful: %d", successful);
}

void onReadyToSend(TcpClient& client, TcpConnectionEvent sourceEvent)
{
	// debug msg
	debugf("onReadyToSend");
	debugf("sourceEvent: %d", sourceEvent);

	// check condition
	if(sourceEvent == eTCE_Connected)
	{
		/* 
		 * T1 = t1
		 * H1 = 8
		 * P1 = 712.15
		 */
		client.sendString("#"+mac+"\n#T1#"+t1+"\n#H1#8\n#P1#712.15\n##", true);
	}
}

bool onReceive(TcpClient& client, char *buf, int size)
{
	// debug msg
	debugf("onReceive");
	debugf("%s", buf);
}

// TcpClient
TcpClient tclient(onCompleted, onReadyToSend, onReceive);

// Connect to remote
void sendData()
{
	t1 += 1.39;
	tclient.connect(REMOTE_HOST, REMOTE_PORT);
}

// Connected to AP
void connectOk()
{
	// debug msg
	debugf("I'm CONNECTED to WiFi");

	mac = WifiStation.getMAC();
	mac.toUpperCase();
	for (int i = 2; i < mac.length(); i += 2)
		mac = mac.substring(0, i) + "-" + mac.substring(i++);

	debugf("mac: %s", mac.c_str());

	procTimer.initializeMs(6 * 60 * 1000, sendData).start();
	sendData();
}

void connectFail()
{
	debugf("I'm NOT CONNECTED!");
	WifiStation.waitConnection(connectOk, 10, connectFail);
}

void init()
{
	Serial.begin(115200);
	Serial.systemDebugOutput(true);
	Serial.println("Hello friendly world! :)");

	WifiAccessPoint.enable(false);

	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiStation.enable(true);

	WifiStation.waitConnection(connectOk, 30, connectFail);
}

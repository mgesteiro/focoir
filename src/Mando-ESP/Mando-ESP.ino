#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

#include "RgbIrLed.h"
RgbIrLed rgbled(0); //Type 0 is IR remote APA1616 24 Button Remote

#define IR_LED 3  // ESP-01 pin 3 (=RX)
IRsend irsend(IR_LED,true,false);  // invertido (off=HIGH) y sin modulación -> to the wire

IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

String responseHTML =
#include "html.h"
;

void atenderPeticion() {
	// servimos la página web con el mando de control
	webServer.send(200, "text/html", responseHTML);
}

void atenderAccion() {
	// obtenemos el comando
	String comando=webServer.arg("comando");
	// enviamos el comando IR (simulado)
	switch (comando[0]) {
	case 'a':
		// statements
		irsend.sendNEC(rgbled.Brighter, 32);
		break;
	case 'b':
		// statements
		irsend.sendNEC(rgbled.Darker, 32);
		break;
	case 'c':
		// statements
		irsend.sendNEC(rgbled.Off, 32);
		break;
	case 'd':
		// statements
		irsend.sendNEC(rgbled.On, 32);
		break;
	case 'e':
		// statements
		irsend.sendNEC(rgbled.Red, 32);
		break;
	case 'f':
		// statements
		irsend.sendNEC(rgbled.Green, 32);
		break;
	case 'g':
		// statements
		irsend.sendNEC(rgbled.Blue, 32);
		break;
	case 'h':
		// statements
		irsend.sendNEC(rgbled.White, 32);
		break;
	case 'i':
		// statements
		irsend.sendNEC(rgbled.BR1, 32);
		break;
	case 'j':
		// statements
		irsend.sendNEC(rgbled.BG1, 32);
		break;
	case 'k':
		// statements
		irsend.sendNEC(rgbled.BB1, 32);
		break;
	case 'l':
		// statements
		irsend.sendNEC(rgbled.Flash, 32);
		break;
	case 'm':
		// statements
		irsend.sendNEC(rgbled.BR2, 32);
		break;
	case 'n':
		// statements
		irsend.sendNEC(rgbled.BG2, 32);
		break;
	case 'o':
		// statements
		irsend.sendNEC(rgbled.BB2, 32);
		break;
	case 'p':
		// statements
		irsend.sendNEC(rgbled.Smooth, 32);
		break;
	case 'q':
		// statements
		irsend.sendNEC(rgbled.BR3, 32);
		break;
	case 'r':
		// statements
		irsend.sendNEC(rgbled.BG3, 32);
		break;
	case 's':
		// statements
		irsend.sendNEC(rgbled.BB3, 32);
		break;
	case 't':
		// statements
		irsend.sendNEC(rgbled.Strobe, 32);
		break;
	case 'u':
		// statements
		irsend.sendNEC(rgbled.BR4, 32);
		break;
	case 'v':
		// statements
		irsend.sendNEC(rgbled.BG4, 32);
		break;
	case 'w':
		// statements
		irsend.sendNEC(rgbled.BB4, 32);
		break;
	case 'x':
		// statements
		irsend.sendNEC(rgbled.Fade, 32);
		break;
	}
	// enviamos el comando de vuelta al cliente web
	webServer.send(200, "text/plain", comando);
}


//##  M A I N  ###############################################################//

void setup() {
	// levantamos punto de acceso
	WiFi.mode(WIFI_AP);
	WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
	WiFi.softAP("FocoRGB");

	// servidor DNS para el portal cautivo
	dnsServer.start(53, "*", apIP); // responde apIP a todas las peticiones

	// servidor WEB para el portal cautivo
	webServer.onNotFound(atenderPeticion);  // respuesta general
	webServer.on("/accion", atenderAccion); // respuesta a acción
	webServer.begin();

	// inicializamos simulador IR
	irsend.begin();
}


void loop() {
	dnsServer.processNextRequest();
	webServer.handleClient();
}

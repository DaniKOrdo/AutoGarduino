#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128 // Ancho de la pantalla OLED
#define ALTO_PANTALLA 64 // Alto de la pantalla OLED

#define OLED_RESET     -1 // Pin reset incluido en algunos modelos de pantallas (-1 si no disponemos de pulsador). 
#define DIRECCION_PANTALLA 0x3C //Dirección de comunicacion: 0x3D para 128x64, 0x3C para 128x32

Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, OLED_RESET);

#define LOGO_WIDTH    84
#define LOGO_HEIGHT   52

const int dry = 559; // 556
const int wet = 390; // 390

int inicio = 0;// Estado de la salida al arrancar arduino
int estadoAC = 0;// Estado actual del boton
int estadoAN = 0;// Variable para guardar el estado anterior del pulsador

void setup() {
  Serial.begin(9600);
  digitalWrite(12, HIGH);
  if(!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_PANTALLA)) {
    Serial.println(F("Fallo en la asignacion de SSD1306"));
  }


  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35,0);
  display.println("danik.dev");
  display.display();


  display.drawLine(0, 10, 128, 10, WHITE);
  display.display();

  display.setTextSize(2);
  display.setCursor(00,20);
  display.println("Humedad: ");
  display.display();
  
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);

  delay(3000);
  
}

void loop() {
  digitalWrite(12, HIGH);
  delay(100000);
  //Serial.println(" ");
  int sensorVal = analogRead(A0);
  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);

  Serial.println(sensorVal);
  Serial.print(percentageHumidity);
  Serial.println("%");

  // PANTALLA //
  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35,0);
  display.println("danik.dev");
  display.display();

  display.drawLine(0, 10, 128, 10, WHITE);
  display.display();

  display.setTextSize(2);
  display.setCursor(00,20);
  display.println("Humedad: ");
  display.display();
  
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  
  display.setCursor(100,20);
  display.println(percentageHumidity);
  display.display();

  ////////////////////////

  // BOTON //
  int estadoBoton = digitalRead(2);
  int estadoBomba = digitalRead(12);
  Serial.print("Estado boton ");
  Serial.println(estadoBoton);
  Serial.print("Estado Bomba ");
  Serial.println(estadoBomba);

  if(estadoBoton == 0) {
    //Serial.println("OFF");
    digitalWrite(12, HIGH);
    delay(2500);
  } else {
    //Serial.println("ON");
    digitalWrite(12, LOW);
    delay(2500);
  }
  ////////////////////////

  delay(1000);
  if(percentageHumidity > 0 && percentageHumidity < 35){
    //Serial.println("ON");
    digitalWrite(12, LOW);
    delay(2500);
    digitalWrite(12, HIGH);
  } else {
    //Serial.println("OFF");
    digitalWrite(12, HIGH);
    delay(2500);
  } 
  
}
                                                                                                                                                             
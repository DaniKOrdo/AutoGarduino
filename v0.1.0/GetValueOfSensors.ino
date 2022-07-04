int maxValue_1 = 0;
int maxValue_2 = 0;
int maxValue_3 = 0;
int maxValue_4 = 0;

int minValue_1 = 600;
int minValue_2 = 600;
int minValue_3 = 600;
int minValue_4 = 600;

const int dry = 600; // (1)600  (4)650-670
const int wet = 400; // (1)400  (4)450

void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    delay(3000);
}

void loop() {
    delay(1000);
    
    int sensorVal_1 = analogRead(A0);
    int sensorVal_2 = analogRead(A1);
    int sensorVal_3 = analogRead(A2);
    int sensorVal_4 = analogRead(A3);

    Serial.println("");
    Serial.println("ACTUAL VALUES");
    Serial.println(sensorVal_1);
    Serial.println(sensorVal_2);
    Serial.println(sensorVal_3);
    Serial.println(sensorVal_4);

    if (sensorVal_1 > maxValue_1) maxValue_1 = sensorVal_1;
    if (sensorVal_2 > maxValue_2) maxValue_2 = sensorVal_2;
    if (sensorVal_3 > maxValue_3) maxValue_3 = sensorVal_3;
    if (sensorVal_4 > maxValue_4) maxValue_4 = sensorVal_4;

    Serial.println("");
    Serial.println("MAX VALUES");
    Serial.println(maxValue_1);
    Serial.println(maxValue_2);
    Serial.println(maxValue_3);
    Serial.println(maxValue_4);

    if (sensorVal_1 < minValue_1) minValue_1 = sensorVal_1;
    if (sensorVal_2 < minValue_2) minValue_2 = sensorVal_2;
    if (sensorVal_3 < minValue_3) minValue_3 = sensorVal_3;
    if (sensorVal_4 < minValue_4) minValue_4 = sensorVal_4;

    Serial.println("");
    Serial.println("MIN VALUES:");
    Serial.println(minValue_1);
    Serial.println(minValue_2);
    Serial.println(minValue_3);
    Serial.println(minValue_4);

}
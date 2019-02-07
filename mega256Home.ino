#include <SoftwareSerial.h>

// constantes de sensores
const int TEMP_SENSOR = A0 ;   
// constantes de comunicacion
const char TEMP_MODULE = '1';
int state = 0;

SoftwareSerial ModBluetooth(10, 11); //TX | RX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(7, OUTPUT);
  ModBluetooth.begin(9600);
  ModBluetooth.print("Modulo conectado");
  ModBluetooth.print("#");
    
}

void loop() {
  char varchar;
  // leemos el puerto de comunicacion bt
  varchar = ModBluetooth.read();
  Serial.println(varchar);

  char curState = switchState(varchar);
  
  if(varchar == '1'){// Leemos la temperatura y
    // accionamos ventilador segun umbral.
    int lecturaTempSensor = analogRead(TEMP_SENSOR);
    float voltaje = 5.0 /1024 * lecturaTempSensor;
    float temp = voltaje * 100;
    Serial.println(temp) ;
    delay(100);
    ModeBluetooth.print(temp);
    ModeBluetooth.print("#");
    if(temp >= umbral) {
      digitalWrite(ledSensor, HIGH);
      digitalWrite(controlVentilador, HIGH);
    }else{
      digitalWrite(ledSensor, LOW);
      digitalWrite(controlVentilador, LOW);
    }
    delay(200);
  }
  
  if(varchar == '1'){
//    digitalWrite(7, HIGH);
    delay(100);
//    ModBluetooth.print("Led Encendido#");
//    Serial.print("Led enecendido");
  }

  if(varchar == '0'){
    //digitalWrite(7, LOW);
    delay(100);
//    ModBluetooth.print("LED apagado#");
//    Serial.print("LED apagado#");
  }
}


char switchState(char varchar){
  if(varchar == 0){
    return varchar;
  }
}

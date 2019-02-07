#include <SoftwareSerial.h>

SoftwareSerial ModBluetooth(10, 11); //TX | RX
// constantes de sensores
const int TEMP_SENSOR = A0 ; 

// accionadores
const int CONTROL_VENT = 9;  

const int UMBRAL = 26;
// constantes de comunicacion
const char TEMP_MODULE = '1';



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(7, OUTPUT);  
  pinMode(CONTROL_VENT, OUTPUT);   
  ModBluetooth.begin(9600);
  ModBluetooth.print("Modulo conectado");
  ModBluetooth.print("#");
    
}

void loop() {
  char varchar;
  // leemos el puerto de comunicacion bt
  varchar = ModBluetooth.read();
  Serial.println(varchar);
  
  switch(varchar){
    case TEMP_MODULE:
      int lecturaTempSensor = analogRead(TEMP_SENSOR);
      float voltaje = 5.0 /1024 * lecturaTempSensor;
      float temp = voltaje * 100;
      Serial.println(temp) ;
      delay(100);
      ModBluetooth.print(temp);
      ModBluetooth.print("#");
      if(temp >= UMBRAL) {
        digitalWrite(CONTROL_VENT, HIGH);
      }else{
        digitalWrite(CONTROL_VENT, LOW);
      }
      delay(200);
      break;
    default:
      Serial.print("hola mundo");
      delay(100);
      ModBluetooth.print("Hola mundo  ");
            ModBluetooth.print(varchar);
      ModBluetooth.print("#");
      break;
  }
 
//  if(varchar == '1'){
////    digitalWrite(7, HIGH);
//    delay(100);
////    ModBluetooth.print("Led Encendido#");
////    Serial.print("Led enecendido");
//  }
//
//  if(varchar == '0'){
//    //digitalWrite(7, LOW);
//    delay(100);
////    ModBluetooth.print("LED apagado#");
////    Serial.print("LED apagado#");
//  }
}

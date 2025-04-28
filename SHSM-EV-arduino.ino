#include <VescUart.h>
#include <SoftwareSerial.h>

const int stage1Pin = 11;
const int stage2Pin = 12;

// due to pull up, 1 is off, 0 is on
int stage1State = 1;
int stage2State = 1;

VescUart UART;
SoftwareSerial altSerial = SoftwareSerial(8, 9); // UART pins

void setup() {
  pinMode(stage1Pin, INPUT_PULLUP);
  pinMode(stage2Pin, INPUT_PULLUP);
  altSerial.begin(115200);

  UART.setSerialPort(&altSerial); // Use UART for connection with VESC
}

void loop() {
  stage1State = digitalRead(stage1Pin);
  stage2State = digitalRead(stage2Pin);
  
  if (!stage1State && !stage2State) {
    UART.setDuty(1.0);
  } else if (!stage1State) {
    UART.setDuty(0.5);
  } else {  
    UART.setDuty(0.0);
  }
  
}
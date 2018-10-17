/*****************************************************************************
    This is an example for the xCHIP SH01

    This examples read data from a SH01 Capacitive Touch Buttons

    You can buy this device on our store!
    -----> https://xinabox.cc/products/SH01/

    The sensors communicates over the I2C Bus
*****************************************************************************/

#include <xCore.h>
#include <xSH01.h>

xSH01 SH01;

void setup() {
  Serial.begin(115200);

  Wire.begin();

  if (SH01.begin()) {
    Serial.println("================================");
    Serial.println("     XINABOX SH01 TouchTest");
    Serial.println("================================");
  } else {
    while (1) {}
  }
}

void loop() {
  SH01.poll();
  if (SH01.touchDetected()) {
    if (SH01.triangleTouched()) {
      Serial.println("Triangle");
    } else if (SH01.circleTouched()) {
      Serial.println("Circle");
    } else if (SH01.squareTouched()) {
      Serial.println("Square");
    } else if (SH01.crossTouched()) {
      Serial.println("Cross");
    }
  }
  delay(1000);
}
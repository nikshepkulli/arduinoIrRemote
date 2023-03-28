#include <IRremote.h>

const int IR_TRANSMIT_PIN = 3;
const int BUTTON_PIN = 4;

IRsend irsend(IR_TRANSMIT_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Button is pressed, send LG code to turn TV on or off
    unsigned long lgCode = 0x20DF10EF; // LG code to be transmitted
    Serial.print("Transmitting LG code: 0x");
    Serial.println(lgCode, HEX);
    irsend.sendNEC(lgCode, 32); // send the code using the NEC protocol with 32 bits
    delay(500); // wait for 0.5 seconds before sending the next code
    }
}

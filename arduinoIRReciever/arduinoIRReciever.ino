#include <IRremote.h>

const int IR_RECEIVE_PIN = 7;

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received LG code: ");
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
}
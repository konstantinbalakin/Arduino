constexpr int LED_PIN = 4;
constexpr int WIRE_PIN = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);

  // pinMode(WIRE_PIN, INPUT);
  pinMode(WIRE_PIN, INPUT_PULLUP); //использую программную подтяжку резистора к питанию
}

void loop() {
  // put your main code here, to run repeatedly:
  bool wireState;

  wireState = !digitalRead(WIRE_PIN); //инвертируем, чтобы в разомкнутом положении диод НЕ горел

  digitalWrite(LED_PIN, wireState);
}
constexpr int LED_GREEN_PIN = 2;
constexpr int LED_YELLOW_PIN = 3;
constexpr int LED_RED_PIN = 4;

constexpr int PAUSE_GREEN = 3000;
constexpr int PAUSE_YELLOW = 2000;
constexpr int PAUSE_RED = 5000;
constexpr int PAUSE_SHORT = 200;
constexpr int BLINK_COUNT = 5;   // Количество миганий

void setup() {
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
}

void loop() {
  // Включить зеленый светодиод на 2 секунды
  digitalWrite(LED_GREEN_PIN, HIGH);
  delay(PAUSE_GREEN);

  // Цикл мигания зеленого светодиода
  for (int i = 0; i < BLINK_COUNT; i++) {
    digitalWrite(LED_GREEN_PIN, HIGH); // Включить светодиод
    delay(PAUSE_SHORT);                // Подождать 200 мс
    digitalWrite(LED_GREEN_PIN, LOW);  // Выключить светодиод
    delay(PAUSE_SHORT);                // Подождать 200 мс
  }

  // Загорается желтый светодиод на 2 секунды
  digitalWrite(LED_YELLOW_PIN, HIGH);
  delay(PAUSE_YELLOW);
  digitalWrite(LED_YELLOW_PIN, LOW);

  // Загорается красный светодиод на 5 секунд
  digitalWrite(LED_RED_PIN, HIGH);
  delay(PAUSE_RED);
  digitalWrite(LED_RED_PIN, LOW);

  // Загорается желтый светодиод на 2 секунды
  digitalWrite(LED_YELLOW_PIN, HIGH);
  delay(PAUSE_YELLOW);
  digitalWrite(LED_YELLOW_PIN, LOW);
}
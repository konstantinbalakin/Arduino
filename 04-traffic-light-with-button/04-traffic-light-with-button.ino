constexpr int LED_GREEN_PIN = 2;
constexpr int LED_YELLOW_PIN = 3;
constexpr int LED_RED_PIN = 4;
constexpr int BUTTON_PIN = 5; // Разъем для кнопки

constexpr int PAUSE_GREEN = 3000;
constexpr int PAUSE_YELLOW = 2000;
constexpr int PAUSE_RED = 5000;
constexpr int PAUSE_SHORT = 200;
constexpr int BLINK_COUNT = 5;

enum State { WAIT_FOR_BUTTON, GREEN_TO_RED, YELLOW_TO_GREEN }; // Состояния

State currentState = WAIT_FOR_BUTTON;

void setup() {
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Кнопка подключена с подтяжкой к питанию
}

void loop() {
  static bool buttonPressed = false;

  // Проверяем нажатие кнопки
  if (digitalRead(BUTTON_PIN) == LOW) { // LOW, так как кнопка замыкается на GND
    if (!buttonPressed) { // Реагируем только на первый переход в LOW
      buttonPressed = true;

      // Меняем состояние
      if (currentState == WAIT_FOR_BUTTON) {
        currentState = GREEN_TO_RED;
      } else if (currentState == GREEN_TO_RED) {
        currentState = YELLOW_TO_GREEN;
      } else {
        currentState = WAIT_FOR_BUTTON;
      }
    }
  } else {
    buttonPressed = false; // Кнопка отпущена
  }

  // Выполняем действия согласно состоянию
  switch (currentState) {
    case WAIT_FOR_BUTTON:
      // Ждем нажатия кнопки
      allLightsOff();
      break;

    case GREEN_TO_RED:
      // Зеленый -> Желтый -> Красный
      greenSequence();
      yellowSequence();
      redSequence();
      currentState = WAIT_FOR_BUTTON; // Возвращаемся к ожиданию
      break;

    case YELLOW_TO_GREEN:
      // Желтый -> Зеленый
      yellowSequence();
      greenSequence();
      currentState = WAIT_FOR_BUTTON; // Возвращаемся к ожиданию
      break;
  }
}

void greenSequence() {
  digitalWrite(LED_GREEN_PIN, HIGH);
  delay(PAUSE_GREEN);

  for (int i = 0; i < BLINK_COUNT; i++) {
    digitalWrite(LED_GREEN_PIN, HIGH);
    delay(PAUSE_SHORT);
    digitalWrite(LED_GREEN_PIN, LOW);
    delay(PAUSE_SHORT);
  }
  digitalWrite(LED_GREEN_PIN, LOW);
}

void yellowSequence() {
  digitalWrite(LED_YELLOW_PIN, HIGH);
  delay(PAUSE_YELLOW);
  digitalWrite(LED_YELLOW_PIN, LOW);
}

void redSequence() {
  digitalWrite(LED_RED_PIN, HIGH);
  delay(PAUSE_RED);
  digitalWrite(LED_RED_PIN, LOW);
}

void allLightsOff() {
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_YELLOW_PIN, LOW);
  digitalWrite(LED_RED_PIN, LOW);
}
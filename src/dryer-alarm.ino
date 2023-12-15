int vibrationPin = A1;
int soundPin = 6;

bool vibrationStarted;

int vibrationThreshold = 5;
int offThreshold = 1000;

int offAt = -1;

void setup() {

  pinMode(vibrationPin, INPUT);
  pinMode(soundPin, OUTPUT);
}

void loop() {
  int vibration = analogRead(vibrationPin);

  // start
  if (!vibrationStarted) {
    if (vibration > vibrationThreshold) {
      vibrationStarted = true;
    }
    return;
  }

  // dryer is running
  if (vibration > vibrationThreshold) {
    offAt = -1;
    return;
  };

  // dryer is paused or stopped
  if (offAt == -1) {
    offAt = millis();
    return;
  }

  // dryer is stopped
  if (millis() - offAt > offThreshold) {
    playTune();
    exit(0);
  }
}

void playNote(int note, float duration) {
  noTone(soundPin);
  tone(soundPin, note * 0.5, duration * 1714);
  delay(duration * 1714);
}

void playTune() {
  playNote(932, 0.25);
  playNote(698, 0.25);
  playNote(1175, 0.25);
  playNote(932, 0.25);

  playNote(1046, 0.125);
  playNote(1175, 0.125);
  playNote(1046, 0.125);
  playNote(932, 0.125);

  playNote(880, 0.25);
  playNote(698, 0.25);

  playNote(1046, 0.125);
  playNote(1175, 0.125);
  playNote(1046, 0.25);

  playNote(880, 0.25);

  playNote(932, 0.125);
  playNote(1046, 0.125);
  playNote(932, 0.125);
  playNote(880, 0.125);
  playNote(784, 0.125);
  playNote(880, 0.125);
  playNote(932, 0.25);
  playNote(932 * 2, 0.125);
}

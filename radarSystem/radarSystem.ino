#include <Servo.h>
#include <math.h> // Include math library for trigonometric functions

// Servo
Servo myservo;

// HC-SR04 ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Laser
const int laserPin = 12;

long duration;
float distance;
float height; // Add height variable
int servoSetting;
bool servoIncreasing = true;

const float MAX_DETECTION_RANGE = 200.0;
const float LASER_ACTIVATION_MIN_RANGE = 1.0;
const float LASER_ACTIVATION_MAX_RANGE = 50.0;

// Define the angle of the sensor
const float sensorAngle = 45.0; // Sensor angle in degrees
const float sensorAngleRad = sensorAngle * PI / 180.0; // Convert angle to radians

// Variabel global untuk kalibrasi
float calibrationFactor = 1.0;
float calibrationOffset = 0.0;

void performCalibration() {
  Serial.println("Starting calibration...");
  
  // Ukur beberapa titik referensi
  float referenceHeights[] = {10.0, 30.0, 50.0}; // cm
  float measuredHeights[3];
  
  for (int i = 0; i < 3; i++) {
    Serial.print("Place object at ");
    Serial.print(referenceHeights[i]);
    Serial.println(" cm height and press any key.");
    while (!Serial.available()) {
      // Tunggu input
    }
    Serial.read(); // Bersihkan buffer
    
    // Lakukan beberapa pengukuran dan ambil rata-rata
    float sum = 0;
    for (int j = 0; j < 10; j++) {
      getDistance();
      sum += height;
      delay(100);
    }
    measuredHeights[i] = sum / 10;
  }
  
  // Hitung faktor kalibrasi dan offset
  float sumXY = 0, sumX = 0, sumY = 0, sumX2 = 0;
  for (int i = 0; i < 3; i++) {
    sumXY += referenceHeights[i] * measuredHeights[i];
    sumX += referenceHeights[i];
    sumY += measuredHeights[i];
    sumX2 += referenceHeights[i] * referenceHeights[i];
  }
  
  calibrationFactor = (3 * sumXY - sumX * sumY) / (3 * sumX2 - sumX * sumX);
  calibrationOffset = (sumY - calibrationFactor * sumX) / 3;
  
  Serial.print("Calibration complete. Factor: ");
  Serial.print(calibrationFactor);
  Serial.print(", Offset: ");
  Serial.println(calibrationOffset);
}

float getCalibratedHeight(float rawHeight) {
  return rawHeight * calibrationFactor + calibrationOffset;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Radar System");

  myservo.attach(11);
  myservo.write(0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW);

  performCaalibration();
}

bool laserActive = false;
unsigned long laserStartTime = 0;
bool autoMode = false;
bool servoStopped = false;

void loop() {
  getDistance();
  readSerialCommand();
  outputDistance();

  if (distance >= LASER_ACTIVATION_MIN_RANGE && distance <= LASER_ACTIVATION_MAX_RANGE && !laserActive) {
    activateLaser();
    servoStopped = true;
  } else if (laserActive && (millis() - laserStartTime >= 2000)) {
    deactivateLaser();
    servoStopped = false;
  }

  if (!laserActive && !servoStopped) {
    if (autoMode) {
      updateServoAuto();
    }
  }

  delay(50);
}

void activateLaser() {
  laserActive = true;
  laserStartTime = millis();
  digitalWrite(laserPin, HIGH);
  Serial.println("LASER_ACTIVATED");
}

void deactivateLaser() {
  laserActive = false;
  digitalWrite(laserPin, LOW);
  Serial.println("LASER_DEACTIVATED");
}

void getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  height = getCalibratedHeight(distance * sin(sensorAngleRad));
  
  // Perubahan perhitungan jarak
  distance = (duration / 2.0) / 29.1;
  
  if (distance > MAX_DETECTION_RANGE) {
    distance = 0;
    height = 0; // If distance is out of range, set height to 0
  } else {
    // Calculate the actual height
    height = distance * sin(sensorAngleRad);
  }
}

void readSerialCommand() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "AUTO") {
      autoMode = true;
      laserActive = false;
      digitalWrite(laserPin, LOW);
    } else if (command == "MANUAL") {
      autoMode = false;
      laserActive = false;
      digitalWrite(laserPin, LOW);
    } else {
      int angle = command.toInt();
      if (angle >= 0 && angle <= 180 && !autoMode) {
        myservo.write(angle);
        servoSetting = angle;
      }
    }
  }
}

void outputDistance() {
  if (distance <= 200) {
    Serial.print(servoSetting);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.println(height); // Add height to the output
  }
}

void updateServoAuto() {
  if (servoIncreasing) {
    servoSetting += 1;
    if (servoSetting >= 180) {
      servoSetting = 180;
      servoIncreasing = false;
    }
  } else {
    servoSetting -= 1;
    if (servoSetting <= 0) {
      servoSetting = 0;
      servoIncreasing = true;
    }
  }
  myservo.write(servoSetting);
}

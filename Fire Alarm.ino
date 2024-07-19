float temp;         // Variable to store temperature
float vout;         // Variable to store the raw analog voltage reading
float vout1;        // Variable to store the converted voltage
int LED = 13;       // LED pin
int gasSensor;      // Variable to store gas sensor reading
int piezo = 7;      // Piezo buzzer pin

void setup() {
  pinMode(A0, INPUT);    // Set analog pin A0 as an input (gas sensor)
  pinMode(A1, INPUT);    // Set analog pin A1 as an input (temperature sensor)
  pinMode(LED, OUTPUT);  // Set digital pin 13 as an output (LED)
  pinMode(piezo, OUTPUT);// Set digital pin 7 as an output (piezo buzzer)
  Serial.begin(9600);    // Begin serial communication at a baud rate of 9600
}

void loop() {
  vout = analogRead(A1);        // Read the voltage from the temperature sensor
  vout1 = (vout / 1024.0) * 5;  // Convert the analog reading to voltage
  temp = (vout1 - 0.5) * 100;   // Convert the voltage to temperature in Celsius

  gasSensor = analogRead(A0);   // Read the gas sensor value

  if (temp >= 80) {             // If the temperature is greater than or equal to 80°C
    digitalWrite(LED, HIGH);    // Turn on the LED
  } else {
    digitalWrite(LED, LOW);     // Turn off the LED
  }

  if (gasSensor >= 100) {       // If the gas sensor reading is greater than or equal to 100
    digitalWrite(piezo, HIGH);  // Turn on the piezo buzzer
    digitalWrite(LED, HIGH);    // Turn on the LED
  } else {
    digitalWrite(piezo, LOW);   // Turn off the piezo buzzer
  }

  Serial.print("in DegreeC= "); // Print "in DegreeC=" to the serial monitor
  Serial.print(" ");
  Serial.print(temp);           // Print the temperature value to the serial monitor
  Serial.print("\t");
  Serial.print("GasSensor= ");  // Print "GasSensor=" to the serial monitor
  Serial.print(" ");
  Serial.print(gasSensor);      // Print the gas sensor value to the serial monitor
  Serial.println();             // Print a new line to the serial monitor

  delay(1000);                  // Wait for 1 second before repeating the loop
}

#include <ms8607.h>

static ms8607 m_ms8607;

boolean OK;

void setup() {
  Serial.begin(9600);

  Serial.println("==== TE Connectivity ====");
  Serial.println("======== MS8607 =========");
  Serial.println("======== Measure ========");
}

void loop() {
  float temperature;
  float pressure;
  float humidity;
  boolean connected;

  boolean = m_ms8607.is_connected();
  if (boolean == true) {
    Serial.println(OK ? "Sensor connencted" : "Sensor disconnected");
    m_ms8607.read_temperature_pressure_humidity(&temperature, &pressure,
                                                &humidity);

    Serial.print("Tempeature = ");
    Serial.print(temperature);
    Serial.print((char)176);
    Serial.println("C");

    Serial.print("Pressure = ");
    Serial.print(pressure);
    Serial.println(" hPa");

    Serial.print("Humidity = ");
    Serial.print(humidity);
    Serial.println("%RH");

    Serial.println("");
  } else {
    Serial.println(boolean ? "Sensor connencted" : "Sensor disconnected");
  }
  delay(1000);
}

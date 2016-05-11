#include <Ultrasonic.h>
#include <Servo.h>

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define SERVO 6 

Servo s; // Variável Servo
int pos; // Posição Servo

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  s.attach(SERVO);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);

  if (cmMsec > 30) {

    s.write(cmMsec);
    digitalWrite(13, HIGH);
  } else {
    s.write(0);
    digitalWrite(13, LOW);
  }
  delay(1000);
}

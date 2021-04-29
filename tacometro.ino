
int RPM;
void ICACHE_RAM_ATTR cuenta() {
  RPM++;
}

void setup() {
Serial.begin(9600);

// Con dos imanes o cuatro aumentamos la precisión
//Lógicamente ajustar la fórmula en el caso de más de 1 imán


// Hall sensor
attachInterrupt(0,cuenta,RISING); //SENSOR: GPIO0 (NodeMCU - D3)
}

void loop() {
 
  
  noInterrupts();
  Serial.print(RPM);
  Serial.print(" RPM sec =>  ");
  Serial.print(RPM*60);
  Serial.println("RPM min. "); 
  RPM=0;
  interrupts(); 
  delay(1000);  //1 sec.
}

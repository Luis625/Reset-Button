const int LAMP = 5;
const int MODULE =  6; 
const int BUTTON = 10;
int cont = 0;


int buttonState = 0;

void setup() {
  
  pinMode(MODULE, OUTPUT);
  pinMode(LAMP, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);

  digitalWrite(LAMP, LOW);
   digitalWrite(MODULE, LOW);
   
  delay(5000);
}

void loop() {
  
  buttonState = 0;
  buttonState = digitalRead(BUTTON); // buttonState = 1 se o botão estiver apertado
                                     // buttonState = 0 se o botão não estiver apertado
                                     
  cont = (buttonState == 1? cont + 1 : 0);
  
  Serial.println(cont);      // Escreve o valor de buttonState
  
  if(cont >= 20){             // Se  buttonState = 1, então ligue a lâmpada e o módulo
    cont  = 0;
    digitalWrite(LAMP, HIGH);
    digitalWrite(MODULE, HIGH);
    delay(5000);
    digitalWrite(MODULE, LOW);
    delay(175000);
    digitalWrite(LAMP, LOW);
  }
  
  delay(10);
}

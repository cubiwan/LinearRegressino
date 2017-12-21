#include <LinearRegression.h>

LinearRegression lr = LinearRegression(0,100);

void setup() {
  lr.learn(1,3);
  lr.learn(2,4);
  lr.learn(3,5);
  lr.learn(4,6);
  lr.learn(5,7);
  lr.learn(6,8);

  Serial.begin(9600); 
    
}

void loop() {
  Serial.print("Result: ");
  Serial.println(lr.calculate(6));

  Serial.print("Correlation: ");
  Serial.println(lr.correlation());
  
  Serial.print("Values: ");

  lr.getValues(values);
  Serial.print("Y = ");
  Serial.print(values[0]);
  Serial.print("*X + ");
  Serial.println(values[1]);  

  delay(2000);
}


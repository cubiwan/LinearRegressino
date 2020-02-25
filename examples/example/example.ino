#include <LinearRegression.h>

LinearRegression lr = LinearRegression();
double values[3];

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
    Serial.println("Start learn");
    lr.learn(1,3);
    lr.learn(2,4);
    lr.learn(3,5);
    lr.learn(4,6);
    lr.learn(5,7);
    lr.learn(6,8);
    Serial.println("End learn");

    Serial.print("Result: 6 -> ");
    Serial.println(lr.calculate(6));

    Serial.print("Result: 7 -> ");
    Serial.println(lr.calculate(7));

    Serial.print("Correlation: ");
    Serial.println(lr.correlation());

    Serial.print("Values: ");
    lr.getValues(values);
    Serial.print("Y = ");
    Serial.print(values[0]);
    Serial.print("*X + ");
    Serial.println(values[1]); 

    Serial.println("Reset");
    lr.reset();

    Serial.print("Values: ");  
    lr.getValues(values);
    Serial.print("X = ");
    Serial.print(values[0]);
    Serial.print(" b = ");
    Serial.print(values[1]); 
    Serial.print(" n = ");
    Serial.println(values[2]); 

    delay(5000);
}

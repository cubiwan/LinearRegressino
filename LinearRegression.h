#ifndef LinearRegression_h
#define LinearRegression_h

#include "Arduino.h"

class LinearRegression
{
  public:
    LinearRegression(int min, int max);
    void learn(int x, int y);
    double calculate(int x);
    double correlation();
    void fixN(int maxN);
    void getValues(double values[]);
  private:
    double meanX = 0;
    double meanX2 = 0; //mean x²
    double varX = 0;
    double meanY = 0;
    double meanY2 = 0; //mean y²
    double varY = 0;
    double meanXY = 0; //mean x*y
    double covarXY = 0;
    int n = 0;
    bool fixedN = false;
    int minX;
    int maxX;
    // m*x + b = y;
    double m = 0;
    double b = 0;
    double r = 0; //correlation
};

#endif

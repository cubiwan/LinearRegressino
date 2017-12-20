#include "Arduino.h"
#include "LinearRegression.h"


LinearRegression::LinearRegression(int min, int max){
  minY = min;
  maxY = max;
}

void LinearRegression::learn(int x, int y){
  if(!fixedN){
    n++;
  }

  if(y < minY){
    return;
  } else if(y > maxY){
    return;
  }

  meanX = meanX + ((x-meanX)/n);
  meanX2 = meanX2 + (((x*x)-meanX2)/n);
  varX = meanX2 - (meanX*meanX);

  meanY = meanY + ((y-meanY)/n);
  meanY2 = meanY2 + (((y*y)-meanY2)/n);
  varY = meanY2 - (meanY*meanY);

  meanXY = meanXY + (((x*y)-meanXY)/n);

  covarXY = meanXY - (meanX*meanY);

  m = covarXY / varX;
  b = meanY-(m*meanX);
}

double LinearRegression::correlation() {
  double stdX = sqrt(varX);
  double stdY = sqrt(varY);
  double stdXstdY = stdX*stdY;
  double correlation;

  if(stdXstdY == 0){
    correlation = 1;
  } else {
    correlation = covarXY / stdXstdY;
  }
  return correlation;
}

double LinearRegression::calculate(int x) {
  return (m*x) + b;
}

void LinearRegression::fixN(int maxN) {
  fixedN = true;
  n = maxN;
}

void LinearRegression::getValues(double values[]){
  values[0] = m;
  values[1] = b;
  values[2] = n;
}

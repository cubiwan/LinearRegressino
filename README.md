# LinearRegressino &nbsp;&nbsp;&nbsp;&nbsp;<a href='https://ko-fi.com/I2I012UF3' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi1.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

Library to calculate linear regression in arduino.

### Create

```c
LinearRegression lr = LinearRegression(0,100);
```

### Methods

```c
LinearRegression(int min, int max);  
```

Initializes object
* min: min value of X
* max: max value of X

```c
void learn(int x, int y);  
```

Learns one example.
* x: value of X
* y: value of Y

```c
double calculate(int x);  
```

Estimates value of Y for X
* x: value of x 

```c
double correlation();  
```

Return actual correlation value

```c
void fixN(int maxN);  
```

Fix value of N (numer of samples) is useful when you need updates continuously
the parameters of the linear regression

```c
void getValues(double values[]);
```

Returns parameters of the linear regression
* values[0] = m;
* values[1] = b;
* values[2] = n;

**Y = m*X + b**

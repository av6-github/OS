#include <stdio.h>
#include <math.h>

typedef struct {
    float real;
    float img;
} Complex;

float absolute(Complex c);
float power(Complex c);

int main() {

    Complex c;
    c.real = 3;
    c.img = 4;

    printf("absolute value is %1.f", absolute(c));
    printf("power is %1.f", power(c));

    return 0;
}
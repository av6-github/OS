#include <stdio.h>
#include <math.h>

typedef struct {
    float real;
    float img;
} Complex;

float absolute(Complex c) {
    return sqrt(c.real*c.real + c.img*c.img);
}

float power(Complex c) {
    return c.real*c.real + c.img*c.img;
}
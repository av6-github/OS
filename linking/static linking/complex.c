#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

Complex add_complex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

Complex mult_complex(Complex a, Complex b) {
    Complex result;
    result.real = a.real*b.real - a.imaginary*b.imaginary;
    result.imaginary = a.real*b.imaginary + a.imaginary*b.real;
    return result;
}
#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

Complex add_complex(Complex a, Complex b);
Complex mult_complex(Complex a, Complex b);

int main() {

    Complex a, b;
    a.real = 5;
    a.imaginary = 3;
    b.real = 2;
    b.imaginary = 1;

    Complex addition = add_complex(a, b);
    Complex multiplication = mult_complex(a, b);

    printf("addition is %1.f + %1.fi \n", addition.real, addition.imaginary);
    printf("multiplication is %1.f + %1.fi \n", multiplication.real, multiplication.imaginary);

    return 0;
}

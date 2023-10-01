#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float SquareRoot(float num, float ans, float tol)
{
    if ( fabs(((ans*ans)-num)) <= tol )
        return ans;
    else
        return SquareRoot( num, ((ans*ans)+num)/(2 * ans), tol);
}

int main()
{
    printf("Raiz quadrada de 5: %f\n\n", SquareRoot(5, 2, 0.01));
    printf("Raiz quadrada de 4: %f\n\n", SquareRoot(4, 2, 0.01));

    return 0;
}
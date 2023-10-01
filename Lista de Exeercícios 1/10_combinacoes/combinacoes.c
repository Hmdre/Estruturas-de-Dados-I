#include <stdio.h>

int C(int n, int k)
{
    if ( k==0 || n==k )
        return 1;
    if ( n > k > 0 )
        return C(n-1, k) + C(n-1, k-1);


}

int main()
{
    printf("Quantidade de combinacoes:%d\n", C(49, 6));
    return 0;
}
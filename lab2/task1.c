#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, gcd;
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    int n3 = atoi(argv[3]);

    printf("Numbers entered are: %d, %d, %d\n", n1,n2,n3);

    for(i=1; i <= n1 && i <= n2 && i <= n3; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0 && n3%i==0)
            gcd = i;
    }

    printf("G.C.D of %d and %d and %d is %d\n", n1, n2, n3, gcd);
    return 0;
}
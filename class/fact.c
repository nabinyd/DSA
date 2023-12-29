#include <stdio.h>
int fact(int n)
{
    if (n == 0)
    {

        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n;
    printf("\nenter the number: ");
    scanf("%d", &n);
    fact(n);
    printf("");
    
    return 0;
}

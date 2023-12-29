#include <stdio.h>
void TOH(int n, char src, char dst, char temp)
{
    if (n == 1)
    {
        printf("move disk%d from %c to %c \n", n, src, dst);
    }
    else
    {
        TOH(n - 1, src, temp, dst);
        printf("move disk%d from %c to %c \n", n, src, dst);
        TOH(n - 1, temp, dst, src);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    TOH(
        n, 'A', 'C', 'B');
    return 0;
}
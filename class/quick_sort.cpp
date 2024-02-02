#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;
void swapp(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;
}

// void mergeSort(int A[], int l, int r)
// {
//     int m;
//     if (l < r)
//     {
//         m = floor((l + r) / 2);
//     }
// }

int partition(int A[], int l, int r)
{
    int x = l;
    int y = r;
    int pivot = A[l];
    while (x < y)
    {
        while (A[x] <= pivot)
        {
            x++;
        }
        while (A[y] > pivot)
        {
            y--;
        }
        if (x < y)
        {
            swapp(&A[x], &A[y]);
        }
    }

    A[l] = A[y];
    A[y] = pivot;
    return y;
}

void quickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int p = partition(A, l, r);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, r);
    }
}
int main()
{
    int A[100000], n, i;
    cout << "Enter number(n) : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    cout << "Before sorting: " << endl;
    display(A, n);
    auto t1 = chrono::high_resolution_clock::now();
    quickSort(A, 0, n - 1);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    cout << "After sorting: " << endl;
    cout << "time: " << duration.count() << endl;
    display(A, n);
    return 0;
}
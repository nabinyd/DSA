#include <iostream>
#include <chrono>
#include <time.h>
#include <math.h>
using namespace std;

int merge(int *A, int left, int mid, int right);
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

void mergeSort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = floor((l + r) / 2);
        cout << "mid: " << m << endl;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int merge(int *A, int left, int mid, int right)
{
    int B[1000];
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= right)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }

    for (k = left; k <= right; k++)
    {
        A[k] = B[k];
    }
    return A[1000];
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
    cout << "After sorting: " << endl;
    mergeSort(A, 0, n);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    display(A, n);
    cout << "time: " << duration.count() << endl;
    return 0;
}
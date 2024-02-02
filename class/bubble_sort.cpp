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

void bubbleSort(int A[], int n)
{
    int i;
    int j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swapp(&A[j], &A[j + 1]);
            }
        }
    }
}

void selectionSort(int A[], int n)
{
    int smallest;
    int position;

    for (int i = 0; i < n; i++)
    {
        smallest = A[i];
        position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < smallest)
            {
                smallest = A[j];
                position = j;
            }
        }
        if (i != position)
        {
            swapp(&A[i], &A[position]);
        }
    }
}

void mergeSort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = floor((l + r) / 2);
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
    // bubbleSort(A, n);
    selectionSort(A, n);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    cout << "After sorting: " << endl;
    cout << "time: " << duration.count() << endl;
    display(A, n);
    return 0;
}
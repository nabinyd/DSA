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

void insertionSort(int A[], int n)
{
    int i;
    int j;
    int temp;
    for (i = 0; i < n; i++)
    {
        j = i - 1;
        temp = A[i];
        while (j >= 0 && temp < A[j])
            
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = temp;
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
    insertionSort(A, n);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    cout << "After sorting: " << endl;
    cout << "time: " << duration.count() << endl;
    display(A, n);
    return 0;
}
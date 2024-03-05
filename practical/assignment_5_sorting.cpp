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
    int choice;
    do
    {
        int A[100000], n, i;
        cout << "Enter number(n) : ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            A[i] = rand();
        }
        cout << "1. Insertion sort";
        cout << "\t2. Selection Sort ";
        cout << "\t3. Bubble Sort ";
        cout << "\t4. Merge Sort";
        cout << "\t5. Quick Sort";
        cout << "\t6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Before sorting: " << endl;
            display(A, n);
            {
                auto t1 = chrono::high_resolution_clock::now();
                insertionSort(A, n);
                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
                cout << "After sorting: " << endl;
                cout << "time: " << duration.count() << endl;
                display(A, n);
            }
            break;
        case 2:
            cout << "Before sorting: " << endl;
            display(A, n);
            {
                auto t1 = chrono::high_resolution_clock::now();
                selectionSort(A, n);
                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
                cout << "After sorting: " << endl;
                cout << "time: " << duration.count() << endl;
                display(A, n);
            }
            break;
        case 3:
            cout << "Before sorting: " << endl;
            display(A, n);
            {
                auto t1 = chrono::high_resolution_clock::now();
                bubbleSort(A, n);
                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
                cout << "After sorting: " << endl;
                cout << "time: " << duration.count() << endl;
                display(A, n);
            }
            break;
        case 4:
            cout << "Before sorting: " << endl;
            display(A, n);
            {
                auto t1 = chrono::high_resolution_clock::now();
                mergeSort(A, 0, n - 1);
                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
                cout << "After sorting: " << endl;
                cout << "time: " << duration.count() << endl;
                display(A, n);
            }
            break;
        case 5:
            cout << "Before sorting: " << endl;
            display(A, n);
            {
                auto t1 = chrono::high_resolution_clock::now();
                quickSort(A, 0, n);
                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
                cout << "After sorting: " << endl;
                cout << "time: " << duration.count() << endl;
                display(A, n);
            }
            break;
        case 6:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (choice != 6);
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;
int merge(int *A, int left, int mid, int right);
int LinearSearch(int A[], int n, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            flag = 1;
            return i;
        }
        cout << A[i] << endl;
    }
    if (flag == 0)
    {
        return -1;
    }
}

int binarySearch(int A[], int l, int r, int key)
{
    int m;
    while (l <= r)
    {
        m = floor((l + r) / 2);
        // cout << "A[" << m << "]: " << A[m] << endl;
        if (A[m] == key)
        {
            return m;
        }
        else if (A[m] > key)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
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
    int A[10000], n, i, key;
    cout << "Enter n: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        A[i] = rand();
    }

    display(A, n - 1);
    mergeSort(A, 0, n-1);
    display(A, n - 1);
    cout << "\nEnter key: " << endl;
    cin >> key;
    int result = binarySearch(A, 0, n - 1, key);
    result == -1 ? cout << "Key not found." : cout << "Key found at index " << result;

    return 0;
}
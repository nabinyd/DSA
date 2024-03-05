#include <iostream>
#include <math.h>
using namespace std;

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
    int choice;
    do
    {
        int A[100000], n, i, key, result;
        cout << "Enter number(n) : ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            A[i] = rand();
        }
        cout << "\nEnter key: " << endl;
        cin >> key;
        cout << "1. linear search";
        cout << "\t2. Binary Search";
        cout << "\t3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            result = LinearSearch(A, n - 1, key);
            display(A, n);
            result == -1 ? cout << "Key not found.\n" : cout << "Key found at index " << result << endl;
            break;
        case 2:
            display(A, n);
            insertionSort(A, n);
            display(A, n);
            result = binarySearch(A, 0, n - 1, key);
            result == -1 ? cout << "Key not found.\n" : cout << "Key found at index " << result << endl;
            break;
        case 3:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;
int Ls(int A[], int n, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            flag = 1;
            return i;
        }
        // cout << A[i] << endl;
    }
    if (flag == 0)
    {
        return -1;
    }
}
int binarySearch(int A[], int l, int r, int key)
{
    int m;
    m = floor((l + r) / 2);
    while (l <= r)
    {
        if (key == A[m])
        {
            return m;
        }
        else if (key < A[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
            m = floor((l + r) / 2);
        }
        cout << "sort" << A[m] << endl;

        return -1;
    }
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
    cout << "enter key" << endl;
    cin >> key;
    binarySearch(A, 0, n - 1, key);
    cout << "sorted" << binarySearch(A, 0, n - 1, key);
    // cout << "key is at position: " << Ls(A, n, key) << endl;
    return 0;
}
#include<iostream>
using namespace std;

void printArr(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void shellSort(int a[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2 )
    {
        for (int i = interval; i < n; ++i)
        {
            int temp = a[i];
            int j = i;          // j = i-1

            //while (j >= 0 && temp < a[j])
            while ( j >= interval && temp < a[j - interval])
            {
                a[j] = a[j - interval]; //a[j+1] = a[j]
                j -= interval; // j -= 1
            }
            a[j] = temp; // a[j+1] = temp
        }
    }

    printArr(a, n);
}

int main()
{
    int a[9] = {4, 3, 5, 6, 7, 8, 9, 1, 2};
    shellSort(a, 9);
}
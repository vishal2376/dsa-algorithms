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

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (a[minIndex] > a[j])
            {
                minIndex = j;
            }
        }
        swap(a[minIndex], a[i]);
    }
    printArr(a, n);
}



int main()
{
    int a[9] = {4, 3, 5, 6, 7, 8, 9, 1, 2};

    selectionSort(a, 9);
}
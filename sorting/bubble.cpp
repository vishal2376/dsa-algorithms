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

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    printArr(a, n);
}


int main()
{
    int a[9] = {4, 3, 5, 6, 7, 8, 9, 1, 2};
    bubbleSort(a, 9);

}
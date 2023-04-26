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

void insertionSort(int a[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int temp = a[i];
        int j = i - 1;

        while (temp < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = temp;
    }

    printArr(a, size);
}


int main()
{
    int a[9] = {4, 3, 5, 6, 7, 8, 9, 1, 2};
    insertionSort(a, 9);

}
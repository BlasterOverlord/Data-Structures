#include <bits/stdc++.h>

using namespace std;

int Partition(int low, int high);
void QuickSort(int low, int high);

vector<int> A;

int main(void)
{
    int n = 8;
    int x;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      A.push_back(x);
    }

    QuickSort(0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}


int Partition(int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[low], A[j]);
    return j;
}


void QuickSort(int low, int high)
{
    if (low < high)
    {
        int j = Partition(low, high);
        QuickSort(low, j-1);
        QuickSort(j+1, high);
    }
}
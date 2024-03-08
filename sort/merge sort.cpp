#include <bits/stdc++.h>

using namespace std;

vector <int> A;

void Merge(int low, int mid, int high)
{
    int m = mid-low+1;
    int n = high-mid;

    vector <int> L;
    vector <int> R;

    for (int i = 0; i < m; i++)
    {
        L.push_back(A[low+i]);
    }
    for (int j = 0; j < n; j++)
    {
        R.push_back(A[mid + j +1]);
    }

    L.push_back(20000000);
    R.push_back(20000000);

    int i = 0, j = 0;

    for (int k = low; k <= high; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}


void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;


        mergeSort(low,mid);

        mergeSort(mid+1, high);

        Merge(low,mid,high);

    }
    return;
}

int main(void)
{
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }

    int low = 0;
    int high = A.size()-1;
    mergeSort(low,high);

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << endl;
    }


    return 0;
}

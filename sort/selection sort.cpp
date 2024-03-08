#include <bits/stdc++.h>

using namespace std;

vector<int> selectionSort(vector <int> list)
{
    int size = list.size();
    int min, temp;
    for (int i = 0; i < size-1; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if (list[min] > list[j])
                min = j;
        }

        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
    return list;
}

int binarySearch(vector <int> list, int target)
{
    int low = 0;
    int high = list.size() - 1;
    int mid;

    while(true)
    {
        mid = (low + high) / 2;

        if (list[mid] == target)
        {
            return mid;
        }
        else if (list[mid] < target)
        {
            low = mid + 1;
        }
        else if (list[mid] > target)
        {
            high = mid - 1;
        }

        if (low > high)
            return -1;
    }
}


int main(void)
{
    vector<int> list;

    cout << "Enter the size of the list: ";
    int size;
    cin >> size;

    cout << "Enter the elements:" << endl;
    int element;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        list.push_back(element);
    }

    list = selectionSort(list);

    int target;
    cout << "Enter a value to search:" << endl;
    cin >> target;

    int result = binarySearch(list, target);

    if (result == -1)
        cout << "Not Found" << endl;
    else
        cout << "Found!" << endl;

    return 0;
}

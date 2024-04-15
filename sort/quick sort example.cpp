#include <bits/stdc++.h>

using namespace std;

int Partition(int low, int high);
void QuickSort(int low, int high);


struct Student
{
    int id;
    string name;
    double cgpa;
};

vector<Student> stds;

int main(void)
{
    int n;
    cout << "How many students?" << endl;
    cin >> n;
    stds.resize(n);

    cout << "Enter student details:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "--- " << "Student " << i+1 << " ---" << endl;
        cout << "ID: ";
        cin >> stds[i].id;
        cout << "Name: ";
        cin >> stds[i].name;
        cout << "CGPA: ";
        cin >> stds[i].cgpa;
    }

    QuickSort(0, n-1);

    cout << "\nStudents sorted in ascending order based on their CGPA:\n" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "--- " << "Student " << i+1 << " ---" << endl;
        cout << "ID: " << stds[i].id << endl;
        cout << "Name: " << stds[i].name << endl;
        cout << "CGPA: " << stds[i].cgpa << endl;
    }

    return 0;
}


int Partition(int low, int high)
{
    double pivot = stds[low].cgpa;
    int i = low;
    int j = high;

    while (i < j)
    {
        while (stds[i].cgpa <= pivot)
        {
            i++;
        }
        while (stds[j].cgpa > pivot)
        {
            j--;
        }

        if (i < j)
            swap(stds[i], stds[j]);
    }

    swap(stds[low], stds[j]);
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

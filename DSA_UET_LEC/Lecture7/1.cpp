#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[j], a[i]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}

void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main()
{
    string file_input;
    string file_output;

    cin >> file_input; //copy path of input file name "numbers.txt"
    cin >> file_output; //copy path of output file name "numbers.sorted"

    ifstream file(file_input);
    ofstream file_out(file_output);

    if (file.is_open())
    {
        string line;
        string s = "";

        while (getline(file, line))
        {
            s += " " + line;
        }

        stringstream ss(s);
        int tmp;
        int a[100000];

        int i = 0;
        while (ss >> tmp)
        {
            a[i] = tmp;
            i++;
        }

        quickSort(a, 0, i - 1);
        for (int j = 0; j < i; j++)
            file_out << a[j] << " ";

        file.close();
    }
    else
        cout << "Can't open file" << endl;

    file_out.close();
    return 0;
}
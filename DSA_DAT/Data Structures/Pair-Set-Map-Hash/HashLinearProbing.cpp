#include <iostream>
#include <math.h>
using namespace std;

class Hash
{
    int size = 0;
    int slots;
    int *table;
    const double a = 0.6180339887;
    int SIZE = 8;
    
public:
    Hash(int slots)
    {
        this->slots = slots;
        table = new int[slots];
        for (int i = 0; i < slots; i++)
        {
            table[i] = -1e9 + 1;
        }
    }

    // unsigned int hashFunction(int key)
    // {
    //     return (2 * key + 5) % slots;
    // }

    unsigned int hashFunction( int k){
		double ka = k * a;
		return floor(SIZE * (ka - (int)ka));
	}

    void insertItem(int key)
    {
        int index = hashFunction(key);
        if (size == slots)
        {
            cout << "Hash table is full" << endl;
            return;
        }
        while (table[index] != -1e9 + 1)
        {
            index = (index + 1) % slots;
        }
        table[index] = key;
        size++;
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        while (table[index] != key)
        {
            index = (index + 1) % slots;
        }
        table[index] = -1e9 + 1;
        size--;
    }

    void searchItem(int key)
    {
        int index = hashFunction(key);
        while (table[index] != key)
        {
            index = (index + 1) % slots;
        }
        cout << "Found " << key << " at index " << index << endl;
    }

    void displayHash()
    {
        for (int i = 0; i < slots; i++)
        {
            cout << i;
            if (table[i] != -1e9 + 1)
            {
                cout << "-->" << table[i];
            }
            cout << endl;
        }
    }
};

// int main()
// {
//     int arr[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
//     int n = 11;
//     Hash h(11);
//     for (int i = 0; i < n; i++)
//     {
//         h.insertItem(arr[i]);
//     }
//     h.displayHash();
//     return 0;
// }

int main(){
    int a[] = {7, 3, 11, 4, 8, 16, 21, 5};
    int n = 8;
    Hash h(8);

    for(int i = 0; i < n; i++){
        h.insertItem(a[i]);
    }
    h.displayHash();
    return 0;
}
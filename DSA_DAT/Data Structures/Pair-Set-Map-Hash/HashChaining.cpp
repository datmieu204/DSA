#include <iostream>
#include <list>
#include<vector>
#include <math.h>

using namespace std;

class Hash
{
    int BUCKET;
    list<int> *table; // Table Hash duoc luu boi 1 list linkedlist
    const double a = 0.6180339887;
    int SIZE = 8;
public:
    Hash(int V)
    {
        this->BUCKET = V;
        table = new list<int>[BUCKET];
    }

    // int hashFunction(int x)
    // {
    //     return (x + 3) % 17;
    // }

    unsigned int hashFunction(int k){
		double ka = k * a;
		return floor(SIZE * (ka - (int)ka));
	}

    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if (*i == key)
            {
                table[index].erase(i);
                break;
            }
        }
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i;
            for (auto x : table[i])
            {
                cout << "-->" << x;
            }
            cout << endl;
        }
    }
};

// int main()
// {
//     int a[] = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};
//     int n = 10;
//     Hash h(17);
//     for (int i = 0; i < n; i++)
//     {
//         h.insertItem(a[i]);
//     }

//     // h.deleteItem(12);
//     h.displayHash();
//     return 0;
// }

int main(){
    int a[] = {7, 3, 11, 4, 8, 16, 21, 5};
    
    Hash h(17);

    for(int i = 0; i < 8; i++){
        h.insertItem(a[i]);
    }

    h.displayHash();
    return 0;
}
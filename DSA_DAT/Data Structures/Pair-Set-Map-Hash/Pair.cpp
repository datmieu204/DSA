#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

// su dung khi muon luu 1 cap hay 1 bo du lieu

int main()
{
    // pair<data_type_1, data_type_2> Pair_name; //default init value to 1
    pair<int, char> PAIR1;
    PAIR1.first = 100;
    PAIR1.second = 'a';

    // pair<data_type_1, data_type_2> Pair_name(value_1, value_2);
    pair<string, double> PAIR2("Mieu", 1.23);

    // make_pair(a, b)
    pair<string, double> PAIR3;
    PAIR3 = make_pair("Dat", 6.8);

    //{a, b}
    pair<string, double> PAIR4;
    PAIR4 = {"cucu", 8.0};

    // copy
    pair<string, double> PAIR5(PAIR4);

    // swap same type
    PAIR3.swap(PAIR4);

    // tie(int&, int&) = pair1;
    pair<int, int> PAIR6 = {1, 2};
    int a, b;
    tie(a, b) = PAIR6;
    cout << a << " " << b << endl; // 1 2
    
    pair<int, int> PAIR7 = {3, 4};
    tie(a, ignore) = PAIR7;
    cout << a << " " << b << endl; // 3 2

    pair<int, pair<int, char>> PAIR8 = {3, {4, 'a'}};
    int x, y;
    char z;
    tie(x, ignore) = PAIR8; // init x
    tie(y, z) = PAIR8.second; // init y,z
    cout << x << " " << y << " " << z << endl; // 3 4 a

    //khi su dung nhieu kieu du lieu -> tuple<data_tye...> name ...;
    //truy cap vao tuple = get<index>(tuple_name);
    tuple<int, int, int, int, int> t{1,2,3,4,5};
    cout << get<0>(t) // 1
         << get<4>(t);// 5

    tuple<string, int, char> x = make_tuple("dat", 25, 'x');


}

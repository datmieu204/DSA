#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int len = s.size();
    string q = s.substr(0, 6);
    cout << q << endl;
    string mys = s.substr(7, len - 8);
    cout << mys << endl;
    stringstream ss(mys);
    int index;
    string res;
    string a, b;
    // char c;
    // if(!((ss >> x >> c >> a) && (ss >> a >> c >> b)) || c != ',') {
    //     cout << x << endl;
    //     cout << a << endl;
    //     cout << b << endl;
    // }

    vector<string> v;
    string x = "";
    while (getline(ss, res, ','))
    {
        v.push_back(res);
        x += " " + res;
    }

    stringstream xx(x);
    xx >> index;
    xx >> a;
    xx >> b;
    cout << index << " "
         << "\n"
         << a << " "
         << "\n"
         << b << " "
         << "\n"
         << x << "\n";

    // cout << v[0].size();
    // a = v[1];
    // b = v[2];

    // cout << x << endl;
    // cout << a << endl;
    // cout << b << endl;

    // stringstream aa(s.substr(3));
    // int id;
    // aa >> id;
    // cout << id << endl;

    return 0;
}
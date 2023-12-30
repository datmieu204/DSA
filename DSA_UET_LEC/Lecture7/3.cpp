#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int a, b ; cin >> a >> b;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    cout << gcd(a, b);
    return 0;
}
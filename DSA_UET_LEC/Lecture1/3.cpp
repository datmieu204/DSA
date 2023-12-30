#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    int a,b;
    do{
        cin >> a >> b;
    }while(a<=0 || b<=0);
    cout << gcd(a,b);
    return 0;
}
#include<iostream>

using namespace std;

int main(){
    string user_in;
    getline(cin,user_in);
    for(int i=user_in.size()-1; i>=0; i--){
        cout << user_in[i];
    }
    return 0;
}
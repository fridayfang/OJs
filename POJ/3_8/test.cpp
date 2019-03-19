#include<iostream>
#include<string>
using namespace std;
int main(){
    string str("test string");
    if(str.size()<-1)cout<<"bugs";
    return 0;
}
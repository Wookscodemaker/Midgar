#include<iostream>
#include<string>
using namespace std;
int main(){
    int i=31415926;
    int n=0;
    do{
        i=i/10;
        n=n+1;
    }while(i>0);
    cout << n;
    return 0;
}
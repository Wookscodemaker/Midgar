#include<iostream>
using namespace std;
void countdown(int n){
    if(n<=0){
        cout << "Blastoff!" << endl;
    }
    else{
        cout << n << endl;
        countdown(n-1);
    }
}
int main(){
    int n;
    cout << "input the number:";
    cin >> n;
    countdown(n);
}

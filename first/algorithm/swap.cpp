#include<iostream>
#include<string>
using namespace std;
int main(){
    int a[3]={0,1,2};
    int b[3];
    memcpy(b,a,sizeof(b));
    printf("%d",b[0]);
    return 0;
}
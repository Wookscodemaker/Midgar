//下面的算法叫做递归算法，及先对两个数进行拆分在求乘积//
#include<iostream>
#include<math.h>
using namespace std;
int main (){
    int a,b,c,n=0,m=0,x,y,k=0,q,w,e,r;
    cin >> a >> b;
    x=a;
    do{
        a=a/10;
        n++;
    }while(a!=0);
    a=x;
    y=b;
    do{
        b=b/10;
        m++;
    }while(b!=0);
    b=y;
    if (n%2!=0){
        k+=1;
        a=10*a;
    }
    if (m%2!=0){
        k+=1;
        b=10*b;
    }
    q=a/pow(10,n/2);w=a%(int)(pow(10,n/2));e=b/pow(10,m/2);r=b%(int)(pow(10,m/2));
    c=((int)(pow(10,((n/2)+(m/2)))*q*e)+(int)(pow(10,n/2)*q*r)+(int)(pow(10,m/2)*w*e)+(w*r))/pow(10,k);
    cout << c;
    return 0;
}

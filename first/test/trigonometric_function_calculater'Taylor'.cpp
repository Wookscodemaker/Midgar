#include<iostream>
#include<cmath>
using namespace std;
double Pi=3.14159265359;
int fac(int x){
    int fac_result=1;
    for(int j=0;j<x;j++){
        fac_result=fac_result*(j+1);
    }
    return fac_result;
}
double operat(double y,int q){
    int p = 2*q-1;
    double res;
    if((q&1)==0){
        res=(-1)*pow(y,p)/fac(p);
    }else{
        res=pow(y,p)/fac(p);
    }
    return res;
}
double sin_calculater(int numerator,int denominator){
    double frac=Pi*numerator/denominator;
    double res0=0;
    for(int i=0;i<9;i++){
        res0=res0+operat(frac,(i+1));
    }
    return res0;
}
int main(){
    cout << "sinΠ*";
    int a,b;
    cin >> a;
    cout << "/";
    cin >> b;
    double res1=sin_calculater(a,b);
    cout <<res1;
    return 0;
}
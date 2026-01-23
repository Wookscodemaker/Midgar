#include<iostream>
#include<cmath>
namespace algorithm{
namespace karatsuba{
/// @brief 简单实现karatsuba算法
/// @param a 使用的两个乘积
/// @param b 使用的两个乘积
/// @return 乘法结果
long long karatsuba_mult(int a,int b){
    long long result;
    long long n,p=0,q=0,s,d,f=0,e=0;
    s=a,d=b;
    do{
        s=s/10;
        p=p+1;
    }while(s>0);
    do{
        d=d/10;
        q=q+1;
    }while(d>0);
    if(p>=q){
        if(p%2==0){
            n=p;
        }else{
            n=p+1;
            f=f+1;
            a=a*10;
        }
        e=n-q;
        b=b*pow(10,e);
    }else{
        if(q%2==0){
            n=q;
        }else{
            n=q+1;
            e=e+1;
            b=b*10;
        }
        f=n-p;
        a=a*pow(10,f);
    }
    long long a1,a2;
    long long b1,b2;
    long long nh;
    nh=n/2;
    a1=a/pow(10,nh);
    b1=b/pow(10,nh);
    a2=a-(a1*pow(10,nh));
    b2=b-(b1*pow(10,nh));
    long long z,x,v,m;
    z=(a1+a2)*(b1+b2);
    v=a1*b1;
    m=a2*b2;
    x=z-v-m;
    result=v*pow(10,n)+x*pow(10,nh)+m;
    result=result/(pow(10,(f+e)));
    return result;
}
}
}
using namespace algorithm;
using namespace karatsuba;
int main(){
    long long ta,tb,res;
    //std::cin >> ta >> tb;
    ta=123123,tb=234234;
    res=karatsuba_mult(ta,tb);
    std::cout << res;
    return 0;
}
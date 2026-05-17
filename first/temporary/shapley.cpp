#include<iostream>
#include<cmath>
using namespace std;
#define Q1 5
#define Q2 3
#define Q3 5
#define L1 20
#define L2 38
int main()
{
    long double C1 = 0;
    long double C2 = 0;
    long double v0=0.0;
    long double v1=0;
    long double v2=0;
    long double v3=0;
    long double v12=0;
    long double v13=0;
    long double v23=0;
    long double v123=0;
    long double T1=0.0;
    long double T2=0.0;
    long double T3=0.0;
    long double N0=1.0/3.0;
    long double N1=1.0/6.0;
    long double N2=1.0/3.0;
    v1=730*pow(Q1,0.712);
    v2=730*pow(Q2,0.712);
    v3=730*pow(Q3,0.712);

    //方案三，1、2联合建厂
    long double QD1=Q1+Q2;
    C1=730*pow(QD1,0.712);
    C2=6.6*L1*pow(Q1,0.51);
    v12=C1+C2;

    //方案四,2、3联合建厂
    long double QD2=Q2+Q3;
    C1=730*pow(QD2,0.712);
    C2=6.6*L2*pow(Q2,0.51);
    v23=C1+C2;
    v13=v1+v3;
    long double QD =Q1+Q2+Q3;//污水厂需要处理的总污水
    long double Qt1 = Q1;//城1到城2的运输量
    long double Qt2 = Q1+Q2;//城2到城3的运输量
    C1 = 730*pow(QD,0.712);
    C2 = 6.6*L1*pow(Qt1,0.51)+6.6*L2*pow(Qt2,0.51);
    v123=C1+C2;
//shapely
    T1=(N0*(v1-v0))+(N1*(v12-v2))+(N1*(v13-v3))+(N2*(v123-v23));
    T2=(N0*(v2-v0))+(N1*(v12-v1))+(N1*(v23-v3))+(N2*(v123-v13));
    T3=(N0*(v3-v0))+(N1*(v23-v2))+(N1*(v13-v1))+(N2*(v123-v12));
    cout <<"v123："<<v123<<endl;
    cout <<"城1的金额："<< T1<<endl;
    cout <<"城2的金额："<<T2<<endl;
    cout <<"城3的金额："<<T3<<endl;
    return 0;
}
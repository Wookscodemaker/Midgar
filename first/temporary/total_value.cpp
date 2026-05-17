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
    long double C_all_1 = 0;//方案一：全部建在城3所需的总资金
    long double C_all_2 = 0;//方案二：每个城市都建立污水处理厂的总资金
    long double C_all_3 = 0;//方案三：城1、城2联合建厂的总资金
    long double C_all_4 = 0;//方案四：城2、城3联合建厂的总资金 
    long double C_all_5 = 0;//方案五：城1、城3联合建厂的总资金   

    //方案一
    long double QD =Q1+Q2+Q3;//污水厂需要处理的总污水
    long double Qt1 = Q1;//城1到城2的运输量
    long double Qt2 = Q1+Q2;//城2到城3的运输量
    C1 = 730*pow(QD,0.712);
    C2 = 6.6*L1*pow(Qt1,0.51)+6.6*L2*pow(Qt2,0.51);
    C_all_1=C1+C2;
    
    //方案二
    C1 = 730*pow(Q1,0.712)+730*pow(Q2,0.712)+730*pow(Q3,0.712);
    C_all_2=C1;
    
    //方案三，1、2联合建厂
    long double QD1=Q1+Q2;
    C1=730*pow(QD1,0.712)+730*pow(Q3,0.712);
    C2=6.6*L1*pow(Q1,0.51);
    C_all_3=C1+C2;

    //方案四,2、3联合建厂
    long double QD2=Q2+Q3;
    C1=730*pow(Q1,0.712)+730*pow(QD2,0.712);
    C2=6.6*L2*pow(Q2,0.51);
    C_all_4=C1+C2;

    //方案五，1,3联合建厂
    long double QD3=Q1+Q3;
    C1=730*pow(QD3,0.712)+730*pow(Q2,0.712);
    C2=6.6*(L1+L2)*pow(Q1,0.51);
    C_all_5=C1+C2;

    
    cout <<"方案一：全部建在城3所需的总资金为："<< C_all_1<<endl;
    cout <<"方案二：每个城市都建立污水处理厂的总资金为："<< C_all_2<<endl;
    cout <<"方案三：城1、城2联合建厂的总资金为："<< C_all_3<<endl;
    cout <<"方案四：城2、城3联合建厂的总资金为："<< C_all_4<<endl;
    cout <<"方案五：城1、城3联合建厂的总资金为： "<< C_all_5<<endl;
    return 0;
}
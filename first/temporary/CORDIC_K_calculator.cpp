#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double CORDIC_K_calculator(int n){
    double res = 1.0;
    double powera=1.0;
    for(int i=0;i<n;i++){
        res=res*(1/sqrt(1.0+1.0/powera));
        powera*=4.0;
    }
    return res;
}
int main(){
    cout << fixed << setprecision(16);
    cout << CORDIC_K_calculator(10000);
    return 0;
}
/*result=0.6072529350088814*/
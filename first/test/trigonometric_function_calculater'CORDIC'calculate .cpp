#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
class DEF{
private:
    static constexpr double Pi = 3.1415926535;
    static constexpr double K = 0.6072529350088814;//定义Pi和K的值
    static constexpr int n = 32;
    std::vector<double> arctan_val;
    void temp(){
        for (size_t i = 0; i < n; i++)
        {
            arctan_val.emplace_back(atan(ldexp(1.0,-i))/Pi);
        }
    }
public:
    DEF(){
        temp();
    }
    double sin_calculator(double theta){
        double radian = theta/180;
        int radianint = static_cast<int>(radian); 
        radian=radian-radianint;
        bool flag=true;
        if((radianint&1)==1){
            flag=false;
        }else{
            flag=true;
        }
        double x=1.0;
        double y=0.0;
        double R=radian;
        for(int i=0;i<n;i++){
            double d =(R>=0)?1.0:-1.0;
            double new_x =x-d*y*ldexp(1.0,-i);
            double new_y =y+d*x*ldexp(1.0,-i);
            R = R-d*arctan_val[i];
            x=new_x;
            y=new_y;
        }
        x=K*x;
        y=K*y;
        return flag?y:-y;
    }
};
int main(){
    DEF def;
    char flag1;
    do{
        cout << "input the degree:";
        double a;
        cin >> a;
        double res1=def.sin_calculator(a);
        cout <<res1 << endl;
        cout << "Do you want to continue?(y/n):";
        cin >> flag1;
    }while(flag1=='y');
    return 0;
} 
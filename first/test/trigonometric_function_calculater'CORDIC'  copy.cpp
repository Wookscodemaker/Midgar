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
        arctan_val.emplace_back(0.2500000000000000);
        arctan_val.emplace_back(0.1475833333333333);
        arctan_val.emplace_back(0.0779777777777778);
        arctan_val.emplace_back(0.0395833333333333);
        arctan_val.emplace_back(0.0198666666666667);
        arctan_val.emplace_back(0.0099444444444444);
        arctan_val.emplace_back(0.0049722222222222);
        arctan_val.emplace_back(0.0024888888888889);
        arctan_val.emplace_back(0.0012444444444444);
        arctan_val.emplace_back(0.0006222222222222);
        arctan_val.emplace_back(0.0003111111111111);
        arctan_val.emplace_back(0.0001555555555556);
        arctan_val.emplace_back(0.0000777777777778);
        arctan_val.emplace_back(0.0000388888888889);
        arctan_val.emplace_back(0.0000194444444444);
        arctan_val.emplace_back(0.0000097222222222);
        arctan_val.emplace_back(0.0000048611111111);
        arctan_val.emplace_back(0.0000024305555556);
        arctan_val.emplace_back(0.0000012152777778);
        arctan_val.emplace_back(0.0000006076388889);
        arctan_val.emplace_back(0.0000003038194444);
        arctan_val.emplace_back(0.0000001519097222);
        arctan_val.emplace_back(0.0000000759548611);
        arctan_val.emplace_back(0.0000000379774306);
        arctan_val.emplace_back(0.0000000189887153);
        arctan_val.emplace_back(0.0000000094943576);
        arctan_val.emplace_back(0.0000000047471788);
        arctan_val.emplace_back(0.0000000023735894);
        arctan_val.emplace_back(0.0000000011867947);
        arctan_val.emplace_back(0.0000000005933974);
        arctan_val.emplace_back(0.0000000002966987);
        arctan_val.emplace_back(0.0000000001483493);
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
        if(radianint&1==1){
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
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<double> arctan_val;
void temp(){
    double Pi = 3.1415926535;
    double K = 0.6072529350088814;//定义Pi和K的值
        arctan_val.emplace_back(1.0/4);
        arctan_val.emplace_back(26.565/180);
        arctan_val.emplace_back(14.036/180);
        arctan_val.emplace_back( 7.125/180);
        arctan_val.emplace_back( 3.576/180);
        arctan_val.emplace_back( 1.790/180);
        arctan_val.emplace_back( 0.895/180);
        arctan_val.emplace_back( 0.448/180);
        arctan_val.emplace_back( 0.224/180);
        arctan_val.emplace_back( 0.112/180);
        arctan_val.emplace_back( 0.056/180);
        arctan_val.emplace_back( 0.028/180);
        arctan_val.emplace_back( 0.014/180);
        arctan_val.emplace_back( 0.007/180);
        arctan_val.emplace_back( 0.0035/180);
        arctan_val.emplace_back( 0.00175/180);
        arctan_val.emplace_back( 0.000875/180);
        arctan_val.emplace_back( 0.0004375/180);
        arctan_val.emplace_back( 0.00021875/180);
        arctan_val.emplace_back( 0.000109375/180);
        arctan_val.emplace_back( 0.0000546875/180);
        arctan_val.emplace_back( 0.00002734375/180);
        arctan_val.emplace_back( 0.000013671875/180);
        arctan_val.emplace_back( 0.0000068359375/180);
        arctan_val.emplace_back( 0.00000341796875/180);
        arctan_val.emplace_back( 0.000001708984375/180);
        arctan_val.emplace_back( 0.0000008544921875/180);
        arctan_val.emplace_back( 0.00000042724609375/180);
        arctan_val.emplace_back( 0.000000213623046875/180);
        arctan_val.emplace_back( 0.0000001068115234375/180);
        arctan_val.emplace_back( 0.00000005340576171875/180);
        arctan_val.emplace_back( 0.000000026702880859375/180);
    }
int main(){
    temp();
    for(int i=0;i<32;i++){
        cout << fixed << setprecision(16);
        cout<<arctan_val[i]<<endl;
    }
    return 0;
}
/*
0.2500000000000000
0.1475833333333333
0.0779777777777778
0.0395833333333333
0.0198666666666667
0.0099444444444444
0.0049722222222222
0.0024888888888889
0.0012444444444444
0.0006222222222222
0.0003111111111111
0.0001555555555556
0.0000777777777778
0.0000388888888889
0.0000194444444444
0.0000097222222222
0.0000048611111111
0.0000024305555556
0.0000012152777778
0.0000006076388889
0.0000003038194444
0.0000001519097222
0.0000000759548611
0.0000000379774306
0.0000000189887153
0.0000000094943576
0.0000000047471788
0.0000000023735894
0.0000000011867947
0.0000000005933974
0.0000000002966987
0.0000000001483493
*/
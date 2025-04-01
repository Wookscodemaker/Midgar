//下面的算法叫做递归算法，及先对两个数进行拆分在求乘积//
#include<iostream>
#include<string>
using namespace std;
int a[1005],b[1005],c[1005];
string mult(string sa,string sb){
    int lena=sa.size(),lenb=sb.size();
    for(int i=0;i<lena;i++){
        a[lena-1-i]=sa[i]-'0';
    }
    for(int i=0;i<lenb;i++){
        b[lenb-1-i]=sb[i]-'0';
    }
    int lff=lena+lenb;
    for(int i=0;i<=lena-1;i++){
        for(int j=0;j<=lenb-1;j++){
            c[i+j]=c[i+j]+(a[i]*b[j]);
        }
    }
    for(int i=0;i<=lff;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    string ff;
    int z;
    for(z=lff-1;z>=0;z--){
        if(c[z]!=0){
            break;
        }
    }
    lff=z+1;
    for(int i=lff-1;i>=0;i--){
        ff+=c[i]+'0';
    }
    return ff;
}
int main (){
    string sa,sb;
    cin >> sa >> sb;
    cout << mult(sa,sb) <<endl;
    return 0;
}

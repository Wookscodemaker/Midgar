#include<iostream>
#include<string>
using namespace std;
int a[1005],b[1005],c[1005];
string sub(string sa,string sb){
    int lena=sa.size(),lenb=sb.size();
    for(int i=0;i<lena;i++)
        a[lena-1-i]=sa[i]-'0';
    for(int i=0;i<lenb;i++)
        b[lenb-1-i]=sb[i]-'0'; 
    int lmax = lena>lenb?lena:lenb;
    for(int i=0;i<lmax;i++){
        a[i]-=b[i];
        if(a[i]<0){
        a[i+1]-=1;
        a[i]+=10;
        }
       // a[i]%=10;
    }
    if(a[lmax])lmax++;
    string ans;
    for(int i=lmax-1;i>=0;i--)
        ans+=a[i]+'0';
    return ans;
}
string mult(string sa,string sb){
    int lena=sa.size(),lenb=sb.size();
    for(int i=0;i<lena;i++){//存储a
        a[lena-1-i]=sa[i]-'0';
    }
    for(int i=0;i<lenb;i++){//存储b
        b[lenb-1-i]=sb[i]-'0';
    }
    int lff = lena+lenb;//最后输出结果的长度
    for(int i=0;i<=lena-1;i++){//进行乘法以及对竖式结果求和的循环
        for(int j=0;j<=lenb-1;j++){
            c[i+j]=c[i+j]+(a[i]*b[j]);
        }
    }
    for(int i=0;i<=lff;i++){//用这个循环进行进位
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    string ff;
    int z;
    for(z=lff-1;z>=0;z--){//将结果中无意义的长度去掉
        if(c[z]!=0){
            break;
        }
    }
    lff=z+1;
    for(int i=lff-1;i>=0;i--){//将最后的结果整合到字符串ff里
        ff+=c[i]+'0';
    }
    return ff;
}
int compare(int sa[1001],int sb[1001],int lena,int lenb){
    if(lena>lenb){
        return 1;
    }else if(lena<lenb){
        return -1;
    }else if(lena==lenb){
        for(int i=lena-1;i>=0;i--){
            if(sa[i]!=sb[i]){
                if(sa[i]>sb[i]){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
        return 0;
    }
    return 0;
}
string divi(string sa,string sb){
    int result[1001];
    int lena=sa.size(),lenb=sb.size();
    for(int i=0;i<lena;i++){//存储a
        a[lena-1-i]=sa[i]-'0';
    }
    for(int i=0;i<lenb;i++){//存储b
        b[lenb-1-i]=sb[i]-'0';
    }
    int lmax=lenb>lena?lenb:lena;
    int lmin=lenb>lena?lena:lenb;
    int max[1001],min[1001];
    if(lenb>lena){
        memcpy(max,b,sizeof(max));
        memcpy(min,a,sizeof(min));
    }else{
        memcpy(max,a,sizeof(max));
        memcpy(min,b,sizeof(min));
    }
    int lff=lmax+1-lmin;
    for(int i=lmax-1;i=0;i--){

    }

}
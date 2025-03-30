#include<iostream>
#include<string>
using namespace std;
char a[1005],b[1005],c[1005];
string mult(string a,string b){
    int lena=a.size(),lenb=b.size();
    for(int i=0;i<lena;i++){
        a[lena-1-i]=a[i]-'0';
    }
    for(int i=0;i<lenb;i++){
        b[lena-1-i]=b[i]-'0';
    }
    int lfinal = lena+lenb;
    if(lena>=lenb){
        for(int i=lena-1;i>=0;i--){
            for(int j=lenb-1;i>=0;i--){
                
            }
        }
    }else{
        for(int i=lenb-1;i>=0;i--){

        }
    }
}
int main(){
    
}
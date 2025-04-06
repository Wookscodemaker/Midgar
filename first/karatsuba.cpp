#include<iostream>
#include<string>
using namespace std;
char a[1005],b[1005];
string add(string sa,string sb){
    int lena=sa.size(),lenb=sb.size();
    for(int i=0;i<lena;i++)
        a[lena-1-i]=sa[i]-'0';
    for(int i=0;i<lenb;i++)
        b[lenb-1-i]=sb[i]-'0'; 
    int lmax = lena>lenb?lena:lenb;
    for(int i=0;i<lmax;i++){
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[lmax])lmax++;
    string ans;
    for(int i=lmax-1;i>=0;i--)
        ans+=a[i]+'0';
    return ans;
}
string KaratdubaMult(string a,string b){
    int n =a.size();
    int m =b.size();
    
    return ;
}
int main(){

}
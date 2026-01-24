#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string add(string sa,string sb){
	int a[1005]={0},b[1005]={0};
    int lena=sa.size(),lenb=sb.size();
    for(int i=0;i<lena;i++)
        a[lena-1-i]=sa[i]-'0';
    for(int i=0;i<lenb;i++)
        b[lenb-1-i]=sb[i]-'0'; 
    int lmax = max(lena,lenb);
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
string sub(string sa, string sb) {
    // 简化：假设 sa >= sb
    int a[1005] = {0}, b[1005] = {0};
    int lena = sa.size(), lenb = sb.size();
    for (int i = 0; i < lena; i++)
        a[lena - 1 - i] = sa[i] - '0';
    for (int i = 0; i < lenb; i++)
        b[lenb - 1 - i] = sb[i] - '0';
    int lmax = max(lena, lenb);
    for (int i = 0; i < lmax; i++) {
        a[i] -= b[i];
        if (a[i] < 0) {
            a[i + 1]--;
            a[i] += 10;
        }
    }
    string ans;
    bool leading = true;
    for (int i = lmax - 1; i >= 0; i--) {
        if (leading && a[i] == 0) continue;
        leading = false;
        ans += a[i] + '0';
    }
    return ans.empty() ? "0" : ans;
}
string mult(string sa,string sb){
	int a[1005],b[1005];
    string pa,pb,pc,pd,pf,pg,ph,presult,result;
    int lena=sa.size(),lenb=sb.size();
    int n;
    int f,e;
    for(int i=0;i<lena;i++){//存储a
        a[i]=sa[i]-'0';
    }
    for(int i=0;i<lenb;i++){//存储b
        b[i]=sb[i]-'0';
    }
    n=max(lena,lenb);
    if(n==0){
        return "0";
    }
    if(n==1){
       int pfin=b[0]*a[0];
       string fin;
       if(pfin>=10){
        fin+=(pfin/10)+'0';
        fin+=(pfin%10)+'0';
       }else{
        fin+=pfin+'0';
       }
       return fin;
    }
    if(n>1){
        if(n%2==1){
            n=n+1;
        }
    }
    int k=n/2;
    f=n-lena;
    e=n-lenb;
    sa = string(n - sa.size(), '0') + sa;
    sb = string(n - sb.size(), '0') + sb;
    pa = sa.substr(0, k);  // 高位
    pb = sa.substr(k);     // 低位
    pc = sb.substr(0, k);
    pd = sb.substr(k);
    ph=mult(pb,pd);
    pf=mult(pa,pc);
    pg=sub(sub(mult(add(pa,pb),add(pc,pd)),ph),pf);
    int lenf=pf.size();
    int leng=pg.size();
    int lenh=ph.size();
    pf.append(n,'0');
    pg.append(k,'0');
    presult=add(pf,add(pg,ph));
    return presult;
}
int main(){
    string sa,sb;
    cin >> sa >> sb;
    cout << mult(sa,sb)  << endl;
    return 0;
}

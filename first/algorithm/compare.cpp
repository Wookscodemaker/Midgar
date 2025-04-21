#include<iostream>
#include<string>
using namespace std;
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
int main(){
    int a[1005],b[1005],i,j;
    int s,l,k;
    string sa,sb;
    cin >> sa >>sb;
    i=sa.size(),j=sb.size();
    for(l=0;l<i;l++){
        a[i-1-l]=sa[l]-'0';
    }
    for(k=0;k<j;k++){
        b[j-1-k]=sb[k]-'0'; 
    }
    s = compare(a,b,i,j);
    cout << s;
    return 0;
}
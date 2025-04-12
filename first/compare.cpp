#include<iostream>
#include<string>
using namespace std;
int compare(int sa[1001],int sb[1001],int lena,int lenb){
    if(lena>lenb){
        return 1;
    }else if(lena<lenb){
        return 0;
    }else if(lena==lenb){
        for(int i=0;i<lena;i++){
            if(sa[i]!=sb[i]){
                if(sa[i]>sb[i]){
                    return 1;
                }else{
                    return 0;

                }
            }
        }
        return -1;
    }
    return -1;
}
int main(){
    int a[1005],b[1005],m,n;
    
    s = compare(a[],b[],i,j);
    cout << s;
    return 0;
}
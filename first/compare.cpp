#include<iostream>
#include<string>
using namespace std;
int compare(string sa,string sb){
    int lena=sa.size(),lenb=sb.size();
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
    int s;
    string sa,sb;
    cin >> sa >> sb;
    s = compare(sa,sb);
    cout << s;
    return 0;
}
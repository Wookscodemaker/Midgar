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
<<<<<<< HEAD
                }else{
                    return 0;
=======
                    break;
                }else{
                    return 0;
                    break;
>>>>>>> 97b9b431f934d4cb5c7443dc45a1ee61f97db608
                }
            }
        }
        return -1;
    }
<<<<<<< HEAD
    return -1;
=======
>>>>>>> 97b9b431f934d4cb5c7443dc45a1ee61f97db608
}
int main(){
    int s;
    string sa,sb;
    cin >> sa >> sb;
    s = compare(sa,sb);
    cout << s;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main(){
    string ans;
    string b = "000001234560000000";
    int a[1005]={0};
    int lmax = b.size();
    for (int i = 0; i < lmax; i++)
        a[lmax - 1 - i] = b[i] - '0';
    bool leading = true;
    for (int i = lmax - 1; i >= 0; i--) {
        if (leading && a[i] == 0) continue;
        leading = false;
        ans += a[i] + '0';
    }
    cout<<ans;
    return 0;
}
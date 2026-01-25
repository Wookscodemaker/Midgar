#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    int n;
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        a.emplace_back(n);
    }
    for (int j = 0; j < 3; j++)
    {
        cout << a[j];
    }
    return 0;
}

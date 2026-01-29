#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string, double> def; 
    def["apple"] = 7999;
    def["xiaomi"] = 1999;
    def["huawei"] = 3999;
    auto it = def.find("xiaomi"); 
    cout << it->second;
    return 0; 
}

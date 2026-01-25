#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;                    // 空 vector
    vector<int> v2(10);                // 10 个元素，默认初始化（0）
    vector<int> v3(10, 5);             // 10 个元素，初始值为 5
    vector<int> v4(v3);                // 拷贝构造
    vector<int> v5(v3.begin(), v3.end()); // 迭代器范围构造
    vector<int> v6 = {1, 2, 3};        // 初始化列表（C++11）           
    vector<int> v7(v3.at(2),v3.at(5));//迭代器范围，与v5不同。迭代是在一个数组内的画一个范围，再将其复制到另一个数组。
    for (int i = 0; i < size(v3); i++)       //对于vetor类型的数组不能直接输出数组中单个的数字，需要用到迭代输出。
    {
        cout << v3.at(i);
    }
    cout << "\n";
    int a=v3.at(0);//vector类型的数组可以将单个数字赋值给变量
    cout << a;
    cout << "\n";
    for (int i = 0; i < size(v2); i++)       //对于vetor类型的数组不能直接输出数组中单个的数字，需要用到迭代输出。
    {
        cout << v2.at(i);
    }
    cout << "\n";
    for (int i = 0; i < size(v5); i++)       //对于vetor类型的数组不能直接输出数组中单个的数字，需要用到迭代输出。
    {
        cout << v5.at(i);
    }
    cout << "\n";
    for (int i = 0; i < size(v7); i++)       //对于vetor类型的数组不能直接输出数组中单个的数字，需要用到迭代输出。
    {
        cout << v7.at(i);
    }
    cout << "\n";
    return 0;
}
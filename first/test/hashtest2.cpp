#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    unordered_map<int, int> nikon; // 哈希表：值 -> 下标
        for (int j = 0; j < size(nums); j++) { // 遍历数组，当前下标为 j
            auto it = nikon.find(target - nums[j]); // 查找是否存在 complement = target - nums[j]
            if (it != nikon.end()) { // 如果找到了
                cout << it->second <<","<< j; // 返回 [之前存的下标, 当前下标 j]
            }
            nikon[nums[j]] = j; // 把当前数字 nums[j] 和它的下标 j 存入哈希表
        }
        return 0; // 理论上不会执行到这（题目保证有解），但函数必须有返回值

}
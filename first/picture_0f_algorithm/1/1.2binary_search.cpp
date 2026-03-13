
//Binary Search二分查找
// 二分查找函数，注意数组必须是有序的。dichotomy是数学上的二分法，而二分查找的英文是binary search
#include <iostream>
#include<vector>
using namespace std;
int dichotomy(vector<int>a,int c){
    int len=a.size()-1;
    int max=len;
    int min=0;
    int mid=0;
    int flag=0;
    int result=0;
    if(a[max]<c||a[min]>c){
        flag=1;
    }
    do{
        mid=(max+min)/2;
        if(a[mid]<c){
            min=mid;
        }
        if(a[mid]>c){
            max=mid;
        }
        if(a[mid]==c){
            result=mid;
            flag=2;
        }
        if(max-min<=1){
            flag=1;
        }
    }while(flag==0);
    if(flag==1){
        result=-1;
    }
    return result;   
}
int main(){
    vector<int> a={1,3,5,6,7,8,9,10};
    int c=5;
    int result=dichotomy(a,c);
    cout << result << endl;
    return 0;
}
/*ai的写法*/
/*
#include <iostream>
#include <vector>
using namespace std;

// 改进后的二分查找函数
int binarySearch(const vector<int>& a, int c) {
    if (a.empty()) return -1;

    int min = 0;
    int max = a.size() - 1;

    while (min <= max) {
        int mid = min + (max - min) / 2; // 防止 (min+max) 溢出的写法，虽然 int 通常够用

        if (a[mid] == c) {
            return mid; // 找到了，直接返回下标
        } else if (a[mid] < c) {
            min = mid + 1; // 关键修正：必须是 mid + 1，否则可能死循环
        } else {
            max = mid - 1; // 关键修正：必须是 mid - 1
        }
    }

    return -1; // 没找到
}

int main() {
    vector<int> a = {1, 3, 5, 6, 7, 8, 9, 10};
    int c = 5;
    
    int result = binarySearch(a, c);
    
    if (result != -1) {
        cout << "Found at index: " << result << " (Value: " << a[result] << ")" << endl;
    } else {
        cout << "Not found" << endl;
    }

    // 测试一个不存在的数
    c = 4;
    result = binarySearch(a, c);
    cout << "Searching for 4: " << result << endl;

    return 0;
}*/
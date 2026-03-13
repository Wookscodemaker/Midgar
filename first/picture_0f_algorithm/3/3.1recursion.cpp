#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    
int find_smallest_recursive(vector<int> a,int n){
    if(n==1){
        return a[0];
    }
    int smallest=find_smallest_recursive(a,n-1);
    if(a[n-1]<smallest){
        return a[n-1];
    }
    else{
        return smallest;
    }
}
void print_arr(vector<int> c){
    int n=c.size();
    for(int i=0;i<n;i++){
        cout << c[i] << ",";
    }
}
vector<int> input_arr(vector<int> d){
    int flag=0;
    do{
        int a;
        cout << "input the number:";
        cin >> a;
        d.push_back(a);
        cout << "Do you want to continue?(y/n):";
        char flag1;
        cin >> flag1;
        if(flag1=='n'){
            flag=1;
        }
    }while(flag==0);
    return d;
}
int main(){
    vector<int> arr2;
    vector<int> arr1=input_arr(arr2);
    int min1=find_smallest_recursive(arr1,arr1.size());
    cout << "The smallest number is:" << min1 << endl;
}
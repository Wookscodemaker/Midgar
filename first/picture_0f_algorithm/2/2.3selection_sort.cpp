#include<iostream>
#include<vector>
using namespace std;
int find_smallest(vector<int> a){
    int smallest=a[0];
    int smallest_index=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            smallest=a[i];
            smallest_index=i;
        }
    }
    return smallest_index;
}
vector<int> selection_sort(vector<int> b){
    vector<int> sorted;
    int n=b.size();
    for(int i=0;i<n;i++){
        int min = find_smallest(b);
        sorted.push_back(b[min]);
        b.erase(b.begin()+min);
    }
    return sorted;
}
/*vector<int> selection_sort(vector<int> arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
    return arr;
}*/
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
    vector<int> input_try;
    vector<int> sorted = selection_sort(input_arr(input_try));
    print_arr(sorted);
    cout << endl;
    /*vector<int> input_try={1,2,3,4,5,6,7,8,9};
    vector<int> sorted = selection_sort(input_try);
    print_arr(sorted);
    cout << endl;*/
    return 0;
}
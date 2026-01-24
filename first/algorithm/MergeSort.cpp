#include<iostream>
#include<cmath>
#include<cstring>
namespace def{
std::string merge(std::string sb,std::string sc){
    std::string result;
    size_t i = 0, j = 0;// 合并两个已排序的子串
    while (i < sb.size() && j < sc.size()) {
        if (sb[i] <= sc[j]) {
            result += sb[i];
            i++;
        } else {
            result += sc[j];
            j++;
        }
    }// 添加剩余字符
    while (i < sb.size()) { 
        result += sb[i];
        i++;
    }
    while (j < sc.size()) {
        result += sc[j];
        j++;
    }

    return result;
}
std::string sort(std::string sa){
    size_t m=sa.size();
    size_t n=m/2;
    if(m<=1){
        return sa;
    }
    std::string b=sa.substr(0,n);
    std::string c=sa.substr(n);
    b=sort(b);
    c=sort(c);
    std::string p=merge(b,c);
    return p;
}
}
int main(){
    std::string la;
    std::cin >> la;
    std::cout << def::sort(la)  << std::endl;
    return 0;
}
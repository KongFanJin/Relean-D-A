#include<iostream>

using namespace std;

// 程序有问题
int binomialFactor(int n, int k){
    if(n == k || k == 0) // n = k = 0;
        return 1;
    if(n == k)
        return 3*binomialFactor(n-1, k-1);
    if(k == 0) 
        return 2*binomialFactor(n-1, k);
    
    return 2*binomialFactor(n-1, k) + 3*binomialFactor(n-1, k-1);
}

int main(){
    cout << binomialFactor(3, 4) << "\n";
    return 0;
}
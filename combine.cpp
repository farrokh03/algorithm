#include <iostream>
using namespace std;

int combine(int n , int k){
    if(n == k || k == 0){
        return 1;
    }
    else
        return combine(n-1,k-1) + combine(n-1 , k);
}

int main(){
    cout<<combine(300,100);
}
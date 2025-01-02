#include <iostream>
using namespace std;

unsigned long long int Combine(int k , int n ){

    int array[n+1][k+1];
    for (int Index = 0 ; Index <= n ; Index++){
        for(int j = 0 ; j <= min(Index , k) ; j++){
            if(Index == j || j == 0 )
                array[Index][j] = 1;
            else
                array[Index][j] = array[Index - 1][j - 1]+array[Index-1][j];
        }
    }
    return array[n][k];
}   


int main (){
    cout<<Combine(600,800);
    return 0;
}
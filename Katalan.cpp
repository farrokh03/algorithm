#include <iostream>
using namespace std;

int Katalan(int n ){
    n = (2*n) - 2;
    int k = n - 1;
    int array[n+1][k+1];
    for (int Index = 0 ; Index <= n ; Index++){
        for(int j = 0 ; j <= min(Index , k) ; j++){
            if(Index == j || j == 0 )
                array[Index][j]= 1;
            else
                array[Index][j] = array[Index - 1][j - 1]+array[Index-1][j];
        }
    }
    return  (1.0000000/n) * array[n][k];
}   
int main(){
}
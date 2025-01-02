#include <iostream>
using namespace std;

unsigned long long int fibonacci( int value ){
    int array[value];
    array[0] = 0 ;
    array[1] =  1 ; 
    
    if( value > 0 )
    for(int Index = 2 ; Index <= value ; Index++){
        array[Index] = array[Index - 1] + array[Index - 2];
    }
    return array[value];
}

int main (){
    int x;
    cin>>x;
    cout<<fibonacci(x);
    return 0;
}
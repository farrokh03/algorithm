#include <iostream>
using namespace std;

void insertation_sort(int Array[] , int ArraySize  ){

    int Index = 1;
    for (Index = 1 ; Index < ArraySize  ; Index ++ ){
        int KeyValue = Array[Index];
        int j = Index - 1 ;
        while(j >= 0 && Array[j] > KeyValue ){
            Array[j+1] = Array[j];
            j--;
        }
        Array[j+1] = KeyValue ;
    }
}
void printarr(int Array[] , int ArraySize ){

    for (int Index = 0 ; Index <ArraySize  ; Index++ ){
        cout << Array[Index]<<'\t';
    }
    cout<<endl;
}

int main (){

    const int ArraySize  = 10;
    int arr[ArraySize ]={47,2,1,32,4,45,6,71,15,11};

    printarr(arr , ArraySize );
    
    insertation_sort(arr , ArraySize );

    printarr(arr , ArraySize );

    return 0;
}
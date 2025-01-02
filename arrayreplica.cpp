#include <iostream>


using namespace std;

class arrayreplica{

    private:
        int array[100];
        int cruiser = 0;
    public:

    void Append(int value){
        array[cruiser] = value;
        cruiser++;

    }
    void Insert(int index , int value ){
        for(int i = cruiser;i>=index; i--){
            array[i+1] = array[i];
        }
            array[index]= value ;
            cruiser++;
   
    }
    void showlist(){
        for(int i = 0 ; i < cruiser  ; i++){
            cout<<array[i]<<"  ";
        }
    }
    void Reverse_Array(int arr[]){

    } 
    void Delete_By_Value(){

    }
    void Delete_By_Index(int val){
    }
    int Linear_Search (){

    }
    int Find_Maximum(){

    }
    int Find_Minimum(){

    }
    int Sum_Of_Array(){

    }
    int Merge_Array(){

    }
    int Find_Duplicate_Elements(){

    }
    int Rotate_Array_To_Left(){

    }
    int Rotate_Array_to_Right(){
        
    }

};


int main (){

    arrayreplica obj;
    obj.Append(10);
    obj.Append(15);
    obj.Insert(1,25);
    obj.showlist();
    
    return 0;

}
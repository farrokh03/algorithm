#include <iostream>
#include <stack>
// time complexity = O(n)
using namespace std;

int largestRectangleArea(int Array[], int size) {
    stack<int> stack; 
    int maxArea = 0; 
    int Index = 0;  

    while (Index < size) {
     
        if (stack.empty() || Array[Index] >= Array[stack.top()]) {
            stack.push(Index); 
            Index++; 
        } else {
          
            int top = stack.top();
            stack.pop();
     
            int height = Array[top];
            int width = stack.empty() ? Index : Index - stack.top() - 1; 
            int area = height * width;
          
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        int height = Array[top];
        int width = stack.empty() ? Index : Index - stack.top() - 1;
        int area = height * width;
        if (area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
}

int main() {
    const int size = 5;
    int Array[size] = {1,2,3,4,5};

    int result = largestRectangleArea(Array, size);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> splitByWhitespace(const string& str) {
    vector<string> result;
    istringstream iss(str); 
    string word;

    while (iss >> word) {
        result.push_back(word);
    }

    return result;
}

using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];  
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++;
        
        while (j >= left && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[left], arr[j]);

  
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main() {
    vector<int> arr ;
    string str; 
    getline(cin, str);  
    vector<string> words = splitByWhitespace(str);

    for (const string& word : words) { 
        arr.push_back(stoi(word)); 
    }
    
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    return 0;
}

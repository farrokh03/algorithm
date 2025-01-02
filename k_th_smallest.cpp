#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
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

int part(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }
    
    int pivotIndex = part(arr, left, right);
    
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int findKthSmallest(int arr[], int n, int k) {
    return quickSelect(arr, 0, n - 1, k - 1); 
}

int main() {
    string x;
    int arr[1000];
    int i = 0;
    int k;
    
    getline(cin, x);  
    vector<string> words = splitByWhitespace(x);

    for (const string& word : words) { 
        arr[i] = stoi(word); 
        i++;
    }     
    cin >> k;
        cout << findKthSmallest(arr, i, k);
    
    return 0;
}

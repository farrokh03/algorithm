#include<iostream>
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

int binary_search(const vector<int>& arr, int low, int haigh, int value) {
    if (low <= haigh) {
        int mid = low + (haigh - low) / 2;
        
        if (arr[mid] == value)
            return mid;
        else if (value > arr[mid])
            return binary_search(arr, mid + 1, haigh, value);
        else
            return binary_search(arr, low, mid - 1, value);
    }
    return -1;
}

int main() {
    vector<int> arr;
    string str; 
    getline(cin, str);  
    vector<string> words = splitByWhitespace(str);

    for (const string& word : words) { 
        arr.push_back(stoi(word)); 
    }

    

    int x;
    cin >> x;
    int index = binary_search(arr, 0, arr.size() - 1, x);
    if (index == -1)
        cout << "Not Found";
    else    
        cout  << x;
    return 0;
}



#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

int main() {
    // Unsorted array data
    int arr[] = {12, 45, 7, 23, 56, 90, 3};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target;

    cout << "Enter the number you want to search for: ";
    cin >> target;
    
    int result = linearSearch(arr, size, target);

    // Output the results
    if (result != -1) {
        cout << "Element found at index by linear search : " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

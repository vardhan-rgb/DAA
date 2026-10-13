#include <iostream>
using namespace std;

// Function for Binary Search (Requires sorted array)
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Finds middle element

        if (arr[mid] == target) {
            return mid; // Element found, return its index
        } else if (arr[mid] < target) {
            low = mid + 1; // Discard the left half
        } else {
            high = mid - 1; // Discard the right half
        }
    }
    return -1; // Element not found
}

int main() {
    // Array must be sorted for Binary Search to work properly
    int arr[] = {3, 7, 12, 23, 45, 56, 90};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target;

    cout << "Enter the number you want to search for: ";
    cin >> target;
    
    int result = binarySearch(arr, size, target);

    // Output the results
    if (result != -1) {
        cout << "Element found at index by binary search : " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

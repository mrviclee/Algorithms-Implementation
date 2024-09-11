#include <iostream>
#include <vector>

// Iterative Binary Search function
int binarySearch(const std::vector<int>& arr, const int& target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int midIdx = start + (end - start) / 2;

        if (arr[midIdx] == target)
        {
            return midIdx;
        }
        else if (arr[midIdx] > target)
        {
            end = midIdx - 1;
        }
        else
        {
            start = midIdx + 1;
        }
    }

    return -1;
}

int main()
{
    // The input array must be sorted
    std::vector<int> arr = { 3, 9, 10, 27, 38, 43, 82, 97, 106, 205, 242 };
    std:: cout << "Sorted Array: [ ";
    for (const auto& num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    // exist in array at index 3
    int target = 27;
    int result = binarySearch(arr, target);
    if (result != -1)
    {
        std::cout << "Target: " << target << " found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Target: " << target << " not found in the array." << std::endl;
    }

    // not exist in array
    target = 30;
    result = binarySearch(arr, target);
    if (result != -1)
    {
        std::cout << "Target: " << target << " found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Target: " << target << " not found in the array." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
unsigned int partition(std::vector<int>& arr, unsigned int start, unsigned int end)
{
    // pick the pivot as the last element of the array
    unsigned int pivotIndex = end;
    int pivot = arr[pivotIndex];

    // initialize the subarray boundry
    // the boundry represents the elements that are on smaller than the pivot and on the left side of the pivot
    int leftSubArrayBoundry = start - 1;

    for (int idx = start; idx < end; idx++)
    {
        // increment the smaller subarray boundry by 1
        // swap the element of the smaller than pivot with the element at the boundry
        // so that all the elements are smaller than the pivot are on the left side  and of the pivot and at the boundry
        if (arr[idx] < pivot)
        {
            leftSubArrayBoundry++;
            std::swap(arr[idx], arr[leftSubArrayBoundry]);
        }
    }

    std::swap(arr[pivotIndex], arr[leftSubArrayBoundry + 1]);

    return leftSubArrayBoundry + 1;
}

// Quick Sort function
void quickSort(std::vector<int>& arr, unsigned int start, unsigned int end)
{
    // keep sorting the left subarray and right subarray
    if (start < end)
    {
        // partition at the array to the left sub array and right sub array
        unsigned int pivot = partition(arr, start, end);

        // sort the left subarray & right subarray
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main()
{
    std::vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };
    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, arr.size() - 1);  // Sort the array

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

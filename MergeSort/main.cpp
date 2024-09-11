#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, unsigned int left, unsigned int mid, unsigned int right)
{
    // initialize two vectors to represent the temporary vectors of the left half and right half
    unsigned int leftHalfLength = mid - left + 1;
    unsigned int rightHalfLength = right - mid;
    std::vector<int> leftHalf(leftHalfLength);
    std::vector<int> rightHalf(rightHalfLength);

    // copy the value from the original vector into the left half and right half
    std::cout << "merge| left: ";
    for (int idx = left; idx <= mid; idx++)
    {
        leftHalf[idx - left] = arr[idx];
        std::cout << leftHalf[idx - left] << " ";
    }
    std::cout << std::endl;

    std::cout << "merge| right: ";
    for (int idx = mid + 1; idx <= right; idx++)
    {
        rightHalf[idx - mid - 1] = arr[idx];
        std::cout << rightHalf[idx - mid - 1] << " ";
    }
    std::cout << std::endl;


    int leftIdx = 0;
    int rightIdx = 0;
    int originalArrIdx = left;

    // iterate through both the left half and right half
    while (leftIdx < leftHalfLength && rightIdx < rightHalfLength)
    {
        // compare the value in left half and right half. move the iterator forward if the value is smaller
        if (leftHalf[leftIdx] < rightHalf[rightIdx])
        {
            arr[originalArrIdx] = leftHalf[leftIdx];
            leftIdx++;
        }
        else
        {
            arr[originalArrIdx] = rightHalf[rightIdx];
            rightIdx++;
        }

        originalArrIdx++;
    }

    // copy the rest of the either vectors to the original vector if there's left over
    std::cout << "leftover: " << leftIdx << " rightover: " << rightIdx << std::endl;
    std::cout << "left len: " << leftHalfLength << " right len: " << rightHalfLength << std::endl;
    while (leftIdx < leftHalfLength)
    {
        arr[originalArrIdx] = leftHalf[leftIdx];
        leftIdx++;
        originalArrIdx++;
    }

    while (rightIdx < rightHalfLength)
    {
        arr[originalArrIdx] = rightHalf[rightIdx];
        rightIdx++;
        originalArrIdx++;
    }

    std::cout << "merge| original: ";
    for (int i = left; i <= right; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void mergeSort(std::vector<int>& arr, unsigned int leftIdx, unsigned int rightIdx)
{
    // split the array by half until it cannot be splitted again
    if (leftIdx < rightIdx)
    {
        // find the middle of the array
        unsigned int midIdx = (leftIdx + rightIdx) / 2;
        std::cout << "mergeSort| left: " << leftIdx << " mid: " << midIdx << " right: " << rightIdx << std::endl;

        // keep splitting the left half and right half
        mergeSort(arr, leftIdx, midIdx);
        mergeSort(arr, midIdx + 1, rightIdx);

        // merge the left half and right half
        merge(arr, leftIdx, midIdx, rightIdx);
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

    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

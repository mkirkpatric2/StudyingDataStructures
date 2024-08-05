

#ifndef TABLEPLAY_QUICKSORT_H
#define TABLEPLAY_QUICKSORT_H

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partitionLowHigh(int arr[], int low, int high)
{

    // initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // condition 1: find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // condition 2: find the first element smaller than
        // the pivot (from last)
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

int partitionHighToLow(int arr[], int low, int high)
{

    // initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        //first element less than
        while (arr[i] >= pivot && i <= high - 1) {
            i++;
        }

        // first element greater than
        while (arr[j] < pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int lowHigh)//lowHigh is bool
{
    //sort Low to High if True
    if (lowHigh) {
        if (low < high) {

            int partitionIndex = partitionLowHigh(arr, low, high);

            quickSort(arr, low, partitionIndex - 1, 1);
            quickSort(arr, partitionIndex + 1, high, 1);
        }
    //Sort High to Low if False
    } else {
        if (low<high){
            int partitionIndex = partitionHighToLow(arr, low, high);

            quickSort(arr, low, partitionIndex - 1, 0);
            quickSort(arr, partitionIndex + 1, high, 0);
        }
    }
}

#endif //TABLEPLAY_QUICKSORT_H

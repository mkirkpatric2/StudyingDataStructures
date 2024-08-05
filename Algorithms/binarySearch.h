//
// Created by M on 8/5/2024.
//

#ifndef ALGOHEADERSFORGITHUB_BINARYSEARCH_H
#define ALGOHEADERSFORGITHUB_BINARYSEARCH_H

// binary search algorithm for arrays of numbers sorted low to high.
int binarySearchLowHigh(int target, int a[], int low, int high){
    int guess = (high+low)/2;
    if (guess==low && (a[guess]!=target && a[guess]+1!=target))
        return -1;
    else if (guess==low && a[guess]+1==target){
        return guess+1;
    }
    else {
        if (a[guess] == target)return guess;
        else if (a[guess] > target) {
            binarySearchLowHigh(target, a, low, guess - 1);
        } else if (a[guess] < target) {
            binarySearchLowHigh(target, a, guess + 1, high);
        }
    }
}

int binarySearchHighLow(int target, int a[], int low, int high){
    int guess = (high+low)/2;
    if (guess==low && (a[guess]!=target && a[guess]+1!=target))
        return -1;
    else if (guess==low && a[guess]+1==target){
        return guess+1;
    }
    else {
        if (a[guess] == target)return guess;
        else if (a[guess] > target) {
            binarySearchHighLow(target, a, guess+1, high);
        } else if (a[guess] < target) {
            binarySearchHighLow(target, a, low, guess-1);
        }
    }
}




#endif //ALGOHEADERSFORGITHUB_BINARYSEARCH_H

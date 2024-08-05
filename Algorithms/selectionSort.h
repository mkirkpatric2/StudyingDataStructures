
#ifndef ALGOHEADERSFORGITHUB_SELECTIONSORT_H
#define ALGOHEADERSFORGITHUB_SELECTIONSORT_H


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int low, int high){
    int index;

    //loop through array high-low times
    for (int y=low;y<high+1;y++){
        index = y;

        //find lowest number. Also chop off already placed numbers from search in future (x=y)
        for (int x = y; x < high; x++) {

            //
            if (a[index] > a[x+1]) {
                index = x+1;

            }
        }
        if(a[high]<a[index]){
            index =high;
        }
        swap(&a[y], &a[index]);
    }
}



#endif //ALGOHEADERSFORGITHUB_SELECTIONSORT_H

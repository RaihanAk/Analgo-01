#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to create array DESCENDING (Worst case) */
void createArray(int A[], int size){
    for (int i = 0; i < size; i++){
        A[i] = size - i;
    }
}

/* Function to pcreateArray(arr, 5000);rint an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[100000];
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    createArray(arr, arr_size);

    /* printf("Given array is \n");
    printArray(arr, arr_size); */
    cout<<"Descending Element \nSize: " <<arr_size <<endl;

    // Begin
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    mergeSort(arr, 0, arr_size - 1);

    // End
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    /* printf("\nSorted array is \n");
    printArray(arr, arr_size); */
    cout<<endl <<duration <<" microseconds" <<endl;
    return 0;
}

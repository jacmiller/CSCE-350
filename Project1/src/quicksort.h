/**
 * Conceived by: Christopher "Jacob" Miller
 * CSCE 350 - O'Reilly
 * 9/6/18
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

using std::swap;

//note returns INDEX of median
//does NOT move the median into the pivot position
template<typename T>
inline
int medianOf3(T A[], int l, int r) {
    //this is overcommented... also, try and avoid using pointers
    T *a = A + l;//array name is just pointer to 1st (0 index) elem., + l shifts l*(T size)
    T *b = A + l + (r - l) / 2;//middle item... int division rounds down
    T *c = A + r;

    //when a is a pointer, *a is the dereference operator (gives value a points to)
    T *m;
    if (*a < *b) {
        if (*b < *c) m = b;
        else if (*c < *a) m = a;
        else m = c;
    } else { //b <=a
        if (*a < *c) m = a;
        else if (*c < *b) m = b;
        else m = c;
    }
    return m - A; //m-A is the number of elements from A[0]

}

//remember: l and r are INLCUSIVE (just like Lomuto)
//make sure to call medianOf3 on the subarray before partitioning
template<typename T>
int hoarePartition(T A[], int l, int r) {
    int pind = medianOf3(A, l, r);
    T p = A[medianOf3(A, l, r)]; //Creates a pivot point, using median of 3 function
    swap(A[pind],A[l]);

    int i = l; //Setting left index
    int j = r + 1; //Setting right index

    while (true) {
        do i=i+1; //Increment i reaching pivot point
        while ( A[i] < p);

        do j = j - 1; //Decrement j from pivot point
        while (A[j] > p);

        if (i >= j) //Halting condition
        {
	    swap(A[l],A[j]);
            return j;
        }
        swap(A[i], A[j]);
    }
    return 0;
}

template<typename T>
void quicksort(T A[], int l, int r) {

    if (l < r) { // Comparison for left/right pivot
        T s = hoarePartition(A,l,r); //Creating new pivot using partition function
        quicksort(A,l,s-1); //Recursive call with left pivot point
        quicksort(A,s+1,r); //Recursive call on right half pivot point
    }
}

#endif

/*
Title: Heapsort, Anagram Checker, BST
Conceived by: Christopher "Jacob" Miller
September 24th, 2018
*/

#ifndef ALGS_H
#define ALGS_H

#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

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
    return 0;
}

template<typename T>
void heapsort(std::vector<T> &V) {
    if (V.empty()) return; //Check for empty vector - no need to sort then

    std::priority_queue<T> q(V.begin(), V.end()); //Create priority queue containing every element of passsed vector
    auto index = V.size() - 1;

    while (q.empty() == false) {
        V[index--] = q.top(); //Accesses top element, subtracting 1 from index each iteration then pops
        q.pop();
    }
}

/*int CountUniqueCharacters(char* str) {
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
        bool appears = false;
        for (int j = 0; j < i; j++) {
            if (str[j] == str[i]) {
                appears = true;
                break;
            }
        }

        if (!appears) {
            count++;
        }
    }
    return count;
}*/

bool are_anagrams(std::string a, std::string b) {

/*    int stringALength = static_cast<int>(a.length());
    int stringBLength = static_cast<int>(b.length());

    char char_arrayA[stringALength];
    char char_arrayB[stringBLength];

    strcpy(char_arrayA, a.c_str());
    strcpy(char_arrayB, b.c_str());

    for (int i = 0; i < a.length(); i++)
    {

    }

    for (int i = 0; i < b.length(); i++)
    {

    }

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
    return a==b;*/

    int freq[256]; //Frequency array created keeping track of occurrences of characters
    memset(freq, 0, sizeof(freq)); //Set memory region to 0 regardless of data type
    int str1_len = a.length(); //Count length of string 1
    int str2_len = b.length(); //Count length of string 2

    for (int i = 0; i < str1_len; i++) { //Iterate through first string
        freq[a[i]]++;
    }

    for (int i = 0; i < str2_len; i++) { //Iterate through second string
        freq[b[i]]--;
    }
    //If both strings were permutations of each other, indices should be 0 of freq array
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;
}


#endif

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

#include <set>
#include <map>

#include<unordered_set>
#include<unordered_map>

#include<stack>
#include<queue>

#include<Windows.h>

using namespace std;


int main()
{
    SetConsoleOutputCP(1252);
    cout << "Umlaute צהü!" << endl;

    // sequentiell <- iteratable

    int array[4];               // fixed size and inplace contiguous
    vector<int> vec;            // dynamic size and place but contigous
                                // spd: O(1)
                                // adding/removing elements in the middle: O(n)
                                // little memory because contingous

    deque<int> deq = { 1,6 };             /* [double ended queue] is an indexed sequence container that allows fast insertion and deletion at both
                                                   its beginning and its end. In addition, insertion and deletion at either end of a deque never 
                                                   invalidates pointers or references to the rest of the elements.*/
                                // spd: O(1) - but slower than vector due to the segmented memory layout
                                // adding/removing at beginning and start O(1) else it's slow
                                // It manages multiple blocks of memory rather than a single contiguous block, which avoids frequent reallocations but incurs some overhead for managing those blocks.
    int firstElement = deq.front();
    int lastElement = deq.back();

    list<int> ls;               // each element contains a pointer to it's previous and next element, good for insertion
                                // spd: O(n) traversing the list for access is required
                                // adding/removing anywhere: O(1)
                                // more memory because of two extra pointers
    forward_list<int> fwdLs;    // each element contains a pointer to the next element

    // associative containers
    set<string> st;                 // each element is unique and no two elements with the same value can exist | ordered by default
                                    // speed of most functions O(log n)
                                    // can iterate
    map<string, int> mp;            // key value pairs. Keys are unique, values don't have to be. | ordered by key by default
                                    // speed of most functions O(log n)
                                    // can iterate

    multiset<string> multist;       // like set but allows duplicates | ordered by default
                                    // speed of most functions O(log n)
                                    // can iterate
    multimap<string, int> multimp;  // like but allows duplicates | ordered by key by default
                                    // speed of most functions O(log n)
                                    // can iterate

    unordered_set<string> unorder_st;               // like set but uses hashtables instead of tree search
                                                    // speed of most functions O(1) <- faster
    unordered_map<double, string> unorderd_map;     // like map but uses hashtables instead of tree search
                                                    // speed of most functions O(1) <- faster

    stack<int> stk;                 // Last In First Out
    queue<int> que;                 // First In First Out


}


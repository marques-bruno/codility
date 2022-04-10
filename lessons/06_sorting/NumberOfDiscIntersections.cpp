// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // compute left & right bounds:
    if (A.size() < 2)
        return 0;
        
    vector<int> l;
    vector<long> r;
    l = vector<int>(A.size());
    r = vector<long>(A.size()); // could have cases where A[i] == INT_MAX && i>0
    for (size_t i = 0 ; i < A.size() ; ++i) {
        l[i] = i - A[i];
        r[i] = long(i) + A[i];
    }
    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());

    int counter = 0;
    for (size_t i = 0 ; i < A.size() ; ++i)
    {
        for (size_t j = i+1 ; j < A.size() ; ++j) {
            if (r[i] < l[j])
                break;
            if (++counter > 10000000) return -1;   
        }
    }
    return counter;
}
// you can use includes, for example:
#include <algorithm>
#include <climits>


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int max_slice = A[0];
    int current_slice = 0;
    for (int i = 0 ; i < N ; ++i) {
        current_slice = max(A[i], A[i] + current_slice);
        max_slice = max(max_slice, current_slice);
    }
    return max_slice;
}

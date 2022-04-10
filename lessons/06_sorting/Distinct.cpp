// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.empty())
        return 0;
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end());

    int c = 1;
    int v = A[0];
    for (int i = 1; i < A.size() ; ++i) {
        if (A[i] != v) {
            v = A[i];
            c++;
        }
    }
    return c;
}

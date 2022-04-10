// you can use includes, for example:
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)

    int Bc = B/K;
    int Ac = A/K;
    if (A%K == 0)
        Ac -= 1;

    return Bc - Ac;
}

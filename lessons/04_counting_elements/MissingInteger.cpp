#include <vector>

int solution(std::vector<int> &A) {
    int N = A.size();
    std::vector<bool> counters(N, false);

    for (int i = 0 ; i < N ; ++i) {
        if (A[i] > 0 && A[i] <= N) {
            counters[A[i] -1] = true;
        }
    }

    for (int i = 0 ; i < N ; ++i) {
        if (!counters[i])
            return i + 1;
    }
    return N + 1;
}

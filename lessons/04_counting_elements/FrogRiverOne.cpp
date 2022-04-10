#include <algorithm>
#include <climits>

int solution(int X, vector<int> &A) {
    vector<int> counters(X+1, -1);

    if (X > A.size())
        return -1;

    for (int i = A.size() -1 ; i >= 0 ; --i)
        counters[A[i]] = i;

    int max = 0;
    for (int i = 1 ; i < counters.size() ; ++i) {
        if (counters[i] == -1)
            return -1;
        max = std::max(counters[i], max);
    }
    return max;
}

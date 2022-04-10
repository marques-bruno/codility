#include <unordered_map>

int solution(vector<int> &A) {
    int N = A.size();
    if (N < 2)
        return A[0] == 1;
    unordered_map<int, int> counters;

    for (int i = 0; i < N ; ++i)
    {
        if (A[i] > N)
            return 0;
        counters[A[i]]++;
    }

    for (auto i : counters)
        if (i.second != 1)
            return 0;
    return 1;
}


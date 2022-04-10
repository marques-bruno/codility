
#include <unordered_map>

int solution(vector<int> &A) {
    int N = A.size();
    unordered_map<int,int> counters;

    for (int i = 0 ; i < N ; ++i)
        counters[A[i]]++;

    for (auto i : counters)
        if (i.second%2)
            return i.first;
    return 0;
}


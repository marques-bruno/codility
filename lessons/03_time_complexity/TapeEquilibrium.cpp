#include <cmath>

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> Asums(N, 0);

    Asums[0] = A[0];
    for (int i = 1 ; i < N ; ++i)
        Asums[i] = Asums[i-1] + A[i];

    int min_diff = abs(Asums[0] - (Asums[N-1] - Asums[0]));
    for (int i = 1 ; i < N-1 ; ++i) {
        int diff = abs(Asums[i] - (Asums[N-1] - Asums[i]));
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

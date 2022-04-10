#include <vector>
using namespace std;

int solution(vector<int> &A) {
    size_t N = A.size();
    float min = (A[0] + A[1]) / 2.0f;
    float min_idx = 0;
    if (A.size() == 2)
        return min_idx;

    for (size_t k = 2 ; k < A.size() ; ++k) {
        size_t j = k-1;
        size_t i = k-2;

        float min2 = (A[i] + A[j]) / 2.0f;
        float min3 = (A[i] + A[j] + A[k]) / 3.0f;
        if (min2 < min) {
            min = min2;
            min_idx = i;
        }
        if (min3 < min) {
            min = min3;
            min_idx = i;
        }
    }
    if ((A[N-2] + A[N-1]) / 2 < min)
        return N-2;
    return min_idx;
}

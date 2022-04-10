#include <algorithm>
#include <vector>

int solution(std::vector<int>& A) {
    int N = A.size();
    if (N < 4)
        return 0;
        
    int j = N-2;
    int low_max = 0;
    int high_max = 0;
    int twoslice_max = 0;

    std::vector<int> sums_slice1(N, 0);
    std::vector<int> sums_slice2(N, 0);
    // Compute the sums, ommit i == 0 & j == N-1  
    for (int i = 1 ; i < N-1 ; ++i) {
        low_max = std::max(0, std::max(A[i] + low_max, A[i]));
        sums_slice1[i] = low_max;
        high_max = std::max(0, std::max(A[j] + high_max, A[j]));
        sums_slice2[j] = high_max;
        j--;
    }

    // Check all slice combinations
    for (int i = 0 ; i < N-2 ; ++i) {
        j = i+2;
        twoslice_max = std::max(twoslice_max, sums_slice1[i] + sums_slice2[j]);
    }
    return twoslice_max;
}


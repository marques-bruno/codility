// you can use includes, for example:
#include <climits>
#include <algorithm>
#include <map>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    std::vector<std::pair<int, size_t>> m(A.size());
    for (size_t i = 0 ; i < A.size() ; ++i) {
        m[i] = std::make_pair(A[i], i);
    }
    std::sort(m.begin(), m.end());

    std::pair<int, size_t> m0, m1, mn1, mn2, mn3;
    m0 = m[0];
    m1 = m[1];
    mn1 = m[A.size()-1];
    mn2 = m[A.size()-2];
    mn3 = m[A.size()-3];
    // if there are consecutive double negatives available (-,-,+ || +,-,- || -+-)
    // and using negatives gets us better result
    if ((m0.first * m1.first * mn1.first) > (mn1.first * mn2.first * mn3.first))
        if (m0.first < 0 && m1.first < 0)
            return m0.first * (m1.first) * (mn1.first);
    return mn1.first * (mn2.first) * (mn3.first);
}

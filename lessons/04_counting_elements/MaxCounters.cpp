#include <algorithm>
#include <vector>

std::vector<int> solution(int N, std::vector<int> &A) {
    std::vector<int> counters(N, 0);
    // keeps track of the max value of any counter
    int max_counter = 0;
    // set to max_counter when N+1 operation shows up,
    // this value is added during counter increments if counter < min_counter
    int min_counter = 0;

    for (auto& i : A) {
        if (i == int(counters.size())+1) {
            min_counter = max_counter;
            continue;
        }
        if (counters[i-1] < min_counter)
            counters[i-1] = min_counter;
        if (++counters[i-1] > max_counter)
            max_counter = counters[i-1];
    }
    // for all counters that weren't increased after the last N+1 operation
    for (auto& c : counters)
        if (c < min_counter)
            c = min_counter;
    return counters;
}

// you can use includes, for example:
#include <algorithm>
#include <climits>


int solution(vector<int> &A) {

  // filter out arrays of size 3 and less
  if (A.size() < 3)
    return 0;

  // first sort numbers:
  std::sort(A.begin(), A.end());

  for (size_t i = 2 ; i < A.size() ; ++i)
    {
      // store in long to handle overflows
      long P(A[i]);
      long Q(A[i-1]);
      long R(A[i-2]);

      // condition
      if (P+Q <= R || Q+R <= P || R+P <= Q)
	continue;
      return 1;
    }
  return 0;
}

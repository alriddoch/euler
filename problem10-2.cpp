#include <iostream>
#include <set>
#include <vector>

using intset = std::set<int>;
using intvector = std::vector<int>;

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " <range>" << std::endl;
    exit(1);
  }

  int range = strtol(argv[1], 0, 10);
  if (range <= 0)
  {
    std::cerr << "range is " << range << "; must be positive." << std::endl;
    exit(1);
  }

  // Build a set of all non-primes under the range, by populating it with
  // all multiples of each prime as we go starting at 2.
  // As we ascend, we determine if the number is prime by whether it is in
  // the set.
  intset nonprimes;
  int64_t prime_sum = 0;
  for (int i = 2; i < range; ++i)
  {
    if (nonprimes.find(i) == nonprimes.end())
    {
      prime_sum += i;
      for (int j = 1; j <= (range / i); ++j)
      {
        nonprimes.insert(i * j);
      }
    }
  }
  std::cout << prime_sum << std::endl;
}

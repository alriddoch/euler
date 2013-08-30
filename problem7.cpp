#include <iostream>
#include <vector>

#include <climits>

typedef std::vector<int> intset;

int check_factors(int n, const intset & primes)
{
  for (int const & i : primes)
  {
    if (n % i == 0)
    {
      return -1;
    }
  }
  return 0;
}

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " <nth>" << std::endl;
    exit(1);
  }

  int nth = strtol(argv[1], 0, 10);
  if (nth <= 0)
  {
    std::cerr << "nth is " << nth << "; must be positive." << std::endl;
    exit(1);
  }
  
  intset primes;
  for (int i = 2; i < INT_MAX; ++i)
  {
    if (check_factors(i, primes) == 0)
    {
      primes.push_back(i);
      if (primes.size() == nth)
      {
        std::cout << i << std::endl;
        exit(0);
      }
    }
  }
  exit(1);
}

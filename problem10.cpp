#include <iostream>

#include <vector>

typedef std::vector<int> intset;

int check_factors(int n, intset const & primes)
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
    std::cerr << "usage: " << argv[0] << " <range>" << std::endl;
    exit(1);
  }

  int range = strtol(argv[1], 0, 10);
  if (range <= 0)
  {
    std::cerr << "range is " << range << "; must be positive." << std::endl;
    exit(1);
  }

  intset primes;
  int64_t prime_sum = 0;
  for (int i = 2; i < range; ++i)
  {
    if (check_factors(i, primes) == 0)
    {
      // std::cout << i << " ";
      primes.push_back(i);
      prime_sum += i;
    }
  }
  std::cout << prime_sum << std::endl;
}

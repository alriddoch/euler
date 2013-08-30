#include <iostream>
#include <vector>

#include <cstdint>

int check_factors(int64_t val, std::vector<int64_t> const & factors)
{
  for (int64_t const & i : factors)
  {
    if (val % i == 0)
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
    std::cerr << "usage: " << argv[0] << " <limit>" << std::endl;
    exit(1);
  }

  int64_t limit = strtol(argv[1], 0, 10);
  int64_t value = limit;
  std::cout << limit << std::endl;

  std::vector<int64_t> primes;
  std::vector<int64_t> prime_factors;

  int64_t factor_limit = limit / 2l + 1l;

  int64_t i = 2;
  for (; i < factor_limit; ++i)
  {
    if (check_factors(i, primes) == 0)
    {
      primes.push_back(i);
      if (limit % i == 0)
      {
        limit /= i;
        value = limit;
        factor_limit = limit / 2l + 1l;
        std::cout << i << " * ";
        prime_factors.push_back(i);
      }
    }
  }

  std::cout << value << std::endl;

  return 0;
}

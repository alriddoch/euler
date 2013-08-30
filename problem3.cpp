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
  std::cout << limit << std::endl;

  std::vector<int64_t> primes;
  std::vector<int64_t> prime_factors;

  int64_t factor_limit = limit / 2l + 1l;

  for (int64_t i = 2; i < factor_limit; ++i)
  {
    if (check_factors(i, primes) == 0)
    {
      std::cout << i << " ";
      primes.push_back(i);
    }
  }

  std::vector<int64_t>::reverse_iterator I = primes.rbegin();
  std::vector<int64_t>::reverse_iterator Iend = primes.rend();
  for (; I != Iend; ++I)
  {
    std::cout << *I << " ";
    if (limit % *I == 0)
    {
      std::cout << std::endl << *I << std::endl;
      return 0;
    }
  }
  std::cout << std::endl;
  return 1;
}

#include <iostream>

#include <map>
#include <vector>

int check_factors(int i, const std::vector<int> & primes)
{
  for (int const & factor : primes)
  {
    if (i % factor == 0)
    {
      return -1;
    }
  }
  return 0;
}

typedef std::map<int, int> intmap;

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << ": <max>" << std::endl;
    exit(1);
  }

  int max = strtol(argv[1], 0, 10);

  if (max <= 0)
  {
    std::cerr << "error: max is " << max << "; must be positive." << std::endl;
    exit(1);
  }

  int max_factor = max / 2 + 1;

  std::vector<int> primes;
  std::map<int, int> empty_factors;

  // Work out all the primes in the range, so we can prime factorize the
  // full range.
  for (int i = 2; i < max; ++i)
  {
    if (check_factors(i, primes) == 0)
    {
      // is is prime
      std::cout << i << " is prime" << std::endl;
      primes.push_back(i);
      empty_factors[i] = 0;
    }
  }

  // For each number in the range, prime factorise, then note the highest
  // power each prime factor is raised to.
  std::map<int, int> factors = empty_factors;
  for (int i = 0; i < max; ++i)
  {
    int val = i;
    std::map<int, int> val_factors = empty_factors;
    std::cout << val << " has ";
    for (int & prime : primes)
    {
      while (val >= prime && val % prime == 0)
      {
        std::cout << prime << " ";
        val /= prime;
        val_factors[prime]++;
      }
    }
    std::cout << std::endl;
    for (int & prime : primes)
    {
      factors[prime] = std::max(factors[prime], val_factors[prime]);
    }
  }

  // Multiple all the primes together, with the highest power required for
  // each of the numbers in the range.
  int lcm = 1;
  for (int & prime : primes)
  {
    for (int i = 0; i < factors[prime]; ++i)
    {
      lcm *= prime;
    }
    std::cout << prime << "^" << factors[prime] << " ";
  }
  std::cout << std::endl;
  std::cout << lcm << std::endl;

  return 0;
}

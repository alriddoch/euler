#include <iostream>
#include <set>
#include <vector>

#include <cassert>
#include <cmath>

using intvector = std::vector<int>;

static bool is_prime(intvector const & primes, int val)
{
  for (int j : primes)
  {
    if (val % j == 0)
    {
      return false;
    }
  }
  return true;
}


static int extend_primes(intvector & primes, int limit)
{
  int largest = primes.back();
  assert(!primes.empty());
  for (int i = primes.back() + 1; i < limit; ++i)
  {
    if (is_prime(primes, i))
    {
      primes.push_back(i);
      largest = i;
    }
  }
  return largest;
}

int factor_count(intvector & primes, int val)
{
  int count = 1;
  std::cout << val << " ";
  for (int p : primes)
  {
    for (int i = 1; std::pow(p, i - 1) <= val; ++i)
    {
      if ((val % std::lrint(std::pow(p, i))) != 0)
      {
        // std::cout << p << "^" << i - 1 << " + ";
        count *= i;
        break;
      }
    }
  }
  // If the divisors counted is 1, this number is prime itself
  if (count == 1)
  {
    primes.push_back(val);
    // std::cout << val << " is prime" << std::endl;
    count = 2;
  }
  std::cout << " = " << count << std::endl;
  return count;
}

int main()
{
  intvector primes{2}; // First prime
  int range = extend_primes(primes, 28);
  int triangle = 28;

  for (int i = 8; ; ++i)
  {
    triangle += i;
    extend_primes(primes, triangle);
    int fc = factor_count(primes, triangle);
    if (fc > 500)
    {
      std::cout << i << ", " << triangle << std::endl;
      break;
    }
  }
}

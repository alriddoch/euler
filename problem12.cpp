#include <iostream>
#include <set>
#include <vector>

int main()
{
  int triangle = 0;
  for (int i = 1; ; ++i)
  {
    triangle += i;
    int divisors = 1;
    for (int j = 2; j <= (triangle / 2); ++j)
    {
      if (triangle % j == 0)
      {
        ++divisors;
      }
    }
    if (divisors > 500)
    {
      std::cout << i << std::endl;
      break;
    }
  }
}

#include <iostream>

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " <sum>" << std::endl;
    exit(1);
  }

  int sum = strtol(argv[1], 0, 10);
  if (sum <= 0)
  {
    std::cerr << "sum is " << argv[1] << "; must be positive" << std::endl;
    exit(1);
  }

  for (int c = 2; c <= sum; ++c)
  {
    for (int b = 1; b < (sum - c); ++b)
    {
      int a = sum - (b + c);
      if (a >= b)
      {
        continue;
      }
      if ((a * a + b * b) == c * c)
      {
        std::cout << a << " + " << b << " + " << c << std::endl;
        std::cout << (a * a) << " + " << (b * b) << " = " << (c * c) << std::endl;
        std::cout << a * b * c << std::endl;
      }
    }
  }
}

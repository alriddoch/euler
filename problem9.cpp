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

  for (int a = 1; a <= sum; ++a)
  {
    for (int b = 1; b <= sum; ++b)
    {
      int c = sum - (a + b);
      if ((a * a + b * b) == c * c)
      {
        std::cout << a << " + " << b << " + " << c << std::endl;
        std::cout << (a * a) << " + " << (b * b) << " = " << (c * c) << std::endl;
        std::cout << a * b * c << std::endl;
      }
    }
  }
}

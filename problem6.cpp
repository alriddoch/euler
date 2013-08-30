#include <iostream>

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " <max>" << std::endl;
    exit(1);
  }

  int max = strtol(argv[1], 0, 10);
  if (max <= 0)
  {
    std::cerr << "max is " << max << ", must be positive." << std::endl;
    exit(1);
  }

  int sumsqu = 0;
  int sum = 0;
  for (int i = 1; i <= max; ++i)
  {
    sum += i;
    sumsqu += i * i;
  }
  std::cout << sum * sum - sumsqu << std::endl;

  return 0;
}

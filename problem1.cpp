#include <iostream>
#include <cstdlib>

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " <limit>" << std::endl;
    exit(1);
  }

  int limit = std::strtol(argv[1], nullptr, 10);

  if (limit <= 0)
  {
    std::cerr << "Limit given: " << limit << ", must be positive" << std::endl;
    exit(1);
  }

  int total = 0;

  for (int i = 0; i < limit; i += 3)
  {
    total += i;
  }

  for (int i = 0; i < limit; i += 5)
  {
    if (i % 3 != 0)
    {
      total += i;
    }
  }

  std::cout << total << std::endl;
}

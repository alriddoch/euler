#include <iostream>

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " <limit>" << std::endl;
    exit(1);
  }

  int limit = std::strtol(argv[1], 0, 10);

  if (limit <= 0)
  {
    std::cerr << "limit is " << limit << ", must be positive." << std::endl;
    exit(1);
  }

  int sum = 0;
  for (int cur = 1, prev = 1, next; cur < limit;)
  {
    if (cur % 2 == 0)
    {
      sum += cur;
    }
    next = cur + prev;
    prev = cur;
    cur = next;
  }

  std::cout << sum << std::endl;

  return 0;
}

#include <iostream>

#include <cstdint>

int digit(char c)
{
  return c - 48;
}

int main(int argc, char ** argv)
{
  if (argc == 1)
  {
    std::cerr << "usage: " << argv[0] << " <string> ..." << std::endl;
    exit(1);
  }

  std::string digits;
  for (int i = 1; i < argc; ++i)
  {
    digits.append(argv[i]);
  }
  std::cout << digits.size() << " digits." << std::endl;

  std::int64_t max = 1;
  size_t len = digits.size() - 12;
  for (size_t s = 0; s < len; ++s)
  {
    std::string sub(digits, s, 13);
    std::int64_t c = 1;
    for (size_t i = 0; i < 13; ++i)
    {
      c *= digit(sub[i]);
    }
    max = std::max(max, c);
  }
  std::cout << max << std::endl;

  return 0;
}

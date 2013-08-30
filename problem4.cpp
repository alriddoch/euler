#include <iostream>

#include <cstring>

int is_palindrome(int n)
{
  char buf[80];
  sprintf(buf, "%d", n);
  size_t l = strlen(buf);
  for (size_t i = 0; i < l/2; ++i)
  {
    if (buf[i] != buf[l - 1 - i])
    {
      return 0;
    }
  }
  std::cout << buf << " is " << n << std::endl;
  return 1;
}

int main()
{
  int largest = -1;

  for (int i = 100; i < 1000; ++i)
  {
    for (int j = 100; j < 1000; ++j)
    {
      auto k = i * j;
      if (is_palindrome(k) && k > largest)
      {
        largest = k;
      }
    }
  }
  std::cout << largest << std::endl;
}

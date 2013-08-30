#include <iostream>

int multiple(int (*grid)[20], int x, int y, int i, int j)
{
  std::cout << "(" << x << "," << y << ")" << grid[x][y] << " "
         << grid[x + i * 1][y + j * 1] << " "
         << grid[x + i * 2][y + j * 2] << " "
         << grid[x + i * 3][y + j * 3] << " ";
  std::cout << grid[x][y] *
         grid[x + i * 1][y + j * 1] *
         grid[x + i * 2][y + j * 2] *
         grid[x + i * 3][y + j * 3] << std::endl;
  return grid[x][y] *
         grid[x + i * 1][y + j * 1] *
         grid[x + i * 2][y + j * 2] *
         grid[x + i * 3][y + j * 3];
}

int main(int argc, char ** argv)
{
  if (argc != 401)
  {
    std::cerr << "usage: " << argv[0] << " <values> ..." << std::endl;
    exit(1);
  }

  int grid[20][20];
  for (int y = 0; y < 20; ++y)
  {
    for (int x = 0; x < 20; ++x)
    {
      grid[x][y] = strtol(argv[y * 20 + x + 1], 0, 10); 
    }
  }

  int max = 0;
  for (int x = 0; x < 20; ++x)
  {
    for (int y = 0; y < 20; ++y)
    {
      if (x < 17)
      {
        max = std::max(max, multiple(grid, x, y, 1, 0));
      }
      if (y < 17)
      {
        max = std::max(max, multiple(grid, x, y, 0, 1));
      }
      if (y < 17 && x < 17)
      {
        max = std::max(max, multiple(grid, x, y, 1, 1));
      }
      if (y > 2 && x < 17)
      {
        max = std::max(max, multiple(grid, x, y, 1, -1));
      }
    }
  }
  std::cout << max << std::endl;
}

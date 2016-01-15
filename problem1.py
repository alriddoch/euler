#!/usr/bin/env python

import sys

def main():
  if len(sys.argv) != 2:
    print "usage: %s <limit>" % sys.argv[0]
    sys.exit(1)

  limit = int(sys.argv[1])

  total = 0

  for i in range(0, limit, 3):
    total += i

  for i in range(0, limit, 5):
    if i % 3 != 0:
      total += i

  print total

if __name__ == '__main__':
  main()

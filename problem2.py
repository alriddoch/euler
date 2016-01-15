#!/usr/bin/env python

import sys

def main():

  if len(sys.argv) != 2:
    print "usage: %d <limit>" % sys.argv[0]
    sys.exit(1)

  limit = int(sys.argv[1])

  total = 0
  cur = 1
  prev = 1

  while cur < limit:
    if cur % 2 == 0:
      total += cur
    nval = cur + prev
    prev = cur
    cur = nval

  print total

if __name__ == '__main__':
  main()

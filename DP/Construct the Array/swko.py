#!/bin/python3
import os

MOD = 1000000007

# Complete the countArray function below.
def countArray(n, k, x):
    only_one, not_one = 1, 0

    for _ in range(2, n + 1):
        only_one, not_one = (k - 1) * not_one % MOD, (only_one + (k - 2) * not_one) % MOD

    return only_one if x == 1 else not_one

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nkx = input().split()

    n = int(nkx[0])

    k = int(nkx[1])

    x = int(nkx[2])

    dp = [None] * (n + 1)

    answer = countArray(n, k, x)

    fptr.write(str(answer) + '\n')

    fptr.close()

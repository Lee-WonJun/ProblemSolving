#!/bin/python3

import math
import os
import random
import re
import sys
import time

# Complete the absolutePermutation function below.
def absolutePermutation(n, k):
    if n < 2 * k:
        return [-1]

    if k == 0:
        return [num for num in range(1, n + 1)]

    values = [None] * n
    s = set()

    for num in range(0, k):
        if num + k <= n:
            values[num] = num + k + 1
            s.add(num + k + 1)
        else:
            return [-1]

    if 2 * k <= n:
        for secondNum in range(2 * k, min(n, 3 * k)):
            if secondNum + 1 + k <= n:
                values[secondNum] = secondNum + 1 + k
                s.add(secondNum + 1 + k)
            else:
                return [-1]

    minValue = min(n, 3 * k)
    for idx in range(k, n):
        if 2 * k <= n and 2 * k <= idx and idx < minValue:
            continue
        value = idx + 1
        if value - k not in s and value - k <= n:
            values[idx] = value - k
            s.add(value - k)
        else:
            if value + k not in s and value + k <= n:
                values[idx] = value + k
                s.add(value + k)
            else:
                return [-1]

    return values

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        result = absolutePermutation(n, k)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()

#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        B = list(map(int, input().rstrip().split()))

        max_num = max(B)

        dp = [[-1] * 2 for _ in range(len(B) + 1)]

        for n in range(1, len(B) + 1):
            if n == 1:
                dp[n][0] = 0
                dp[n][1] = 0
            else:
                dp[n][0] = max(dp[n-1][0], dp[n-1][1] + abs(B[n-2] - 1))
                dp[n][1] = max(dp[n-1][0] + abs(B[n-1] - 1), dp[n-1][1] + abs(B[n-1] - B[n-2]))

        fptr.write(str(max(dp[n][0], dp[n][1])) + '\n')

    fptr.close()

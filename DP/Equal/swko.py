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

        arr = list(map(int, input().rstrip().split()))

        min_num = min(arr)
        diff_nums = [n - min_num for n in arr]
        diff_nums_one = [n + 1 for n in diff_nums]
        diff_nums_two = [n + 2 for n in diff_nums]
        diff_nums_five = [n + 5 for n in diff_nums]

        dp = [None] * (max(diff_nums) + 6)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 1
        dp[3] = 2
        dp[4] = 2
        dp[5] = 1

        if 6 < len(dp):
            for i in range(6, len(dp)):
                dp[i] = min(dp[i - 1], dp[i - 2], dp[i - 5]) + 1

        result = 0
        result_one = 0
        result_two = 0
        result_five = 0

        for num in diff_nums:
            result += dp[num]

        for num in diff_nums_one:
            result_one += dp[num]

        for num in diff_nums_two:
            result_two += dp[num]

        for num in diff_nums_five:
            result_five += dp[num]

        fptr.write(str(min(result, result_one, result_two, result_five)) + '\n')

    fptr.close()

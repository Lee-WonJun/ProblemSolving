#!/bin/python3

import math
import os
import random
import re
import sys

dirs = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

# Complete the queensAttack function below.
def queensAttack(n, obstacles, r_q, c_q):
    cnt = 0
    for dir in dirs:
        curPos = [r_q, c_q]
        y = dir[0]
        x = dir[1]
        curPos[0] += y
        curPos[1] += x
        while 1 <= curPos[0] and curPos[0] <= n and 1 <= curPos[1] and curPos[1] <= n and (curPos[0], curPos[1]) not in obstacles:
            cnt += 1
            curPos[0] += y
            curPos[1] += x

    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    r_qC_q = input().split()

    r_q = int(r_qC_q[0])

    c_q = int(r_qC_q[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(tuple(map(int, input().split())))

    result = queensAttack(n, set(obstacles), r_q, c_q)

    fptr.write(str(result) + '\n')

    fptr.close()

#!/bin/python3
import os

posArr = [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]

def isMagicSquare(s):
    sum = s[0][0] + s[0][1] + s[0][2]
    for i in range(3):
        if s[0][i] + s[1][i] + s[2][i] != sum:
            return False
        if s[i][0] + s[i][1] + s[i][2] != sum:
            return False

    if s[0][0] + s[1][1] + s[2][2] != sum:
        return False
    if s[0][2] + s[1][1] + s[2][0] != sum:
        return False

    return True

def formingMagicSquare(s, posIndex, cost, nums):
    if posIndex == 9:
        if isMagicSquare(s):
            return cost
        else:
            return 100000

    answer = 100000

    for num in nums:
        origin = s[posArr[posIndex][0]][posArr[posIndex][1]]

        s[posArr[posIndex][0]][posArr[posIndex][1]] = num

        temp = nums.copy()
        temp.remove(num)
        answer = min(answer, formingMagicSquare(s, posIndex + 1, cost + abs(origin - num), temp))

        s[posArr[posIndex][0]][posArr[posIndex][1]] = origin

    return answer

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = []

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    nums = set()

    for num in range(1, 10):
        nums.add(num)

    result = formingMagicSquare(s, 0, 0, nums)

    fptr.write(str(result) + '\n')

    fptr.close()

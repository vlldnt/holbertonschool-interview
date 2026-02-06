#!/usr/bin/python3
'''Find minimum amount of coin to get to total'''


def makeChange(coins, total):
    '''mini coins to get total'''
    if total <= 0:
        return 0
    sortedCoins = sorted(coins, reverse=True)
    coin = 0

    for i in range(0, len(sortedCoins)):
        while total >= sortedCoins[i]:
            total -= sortedCoins[i]
            coin += 1
            if total == 0:
                return coin
        i += 1
    return -1

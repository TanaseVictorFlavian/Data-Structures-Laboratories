from random import randrange
import sys

list = " ".join(map(str,[randrange(-100, 100) for _ in range(100)]))

print(list)

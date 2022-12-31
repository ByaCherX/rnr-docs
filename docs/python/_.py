
import random
from sys import stdout
secret_number = random.randint(1,10)
print ("Pick a number between 1 to 10")
print(secret_number)
while True:
    res = input("Guess the number: ")
    if res==secret_number:
        print ("You win")
        break
    else:
        print ("You lose")
        continue
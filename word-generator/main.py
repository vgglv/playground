import random
import string
import argparse

parser = argparse.ArgumentParser("Word Generator 2000", "main.py <length-of-your-word>")
parser.add_argument('length', type=int)
args = parser.parse_args()
result: str = ''
for i in range(args.length):
    r = random.randint(0, 100)
    if (r <= 50):
        result += str(random.choice(string.ascii_letters))
    elif (r <= 80):
        result += str(random.choice(string.digits))
    else:
        result += str(random.choice(string.punctuation))

print(f"Your word is: {result}")
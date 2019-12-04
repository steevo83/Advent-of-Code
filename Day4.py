# --- Day 4: Secure Container ---

# You arrive at the Venus fuel depot only to discover it's protected by a password. The Elves had written the password on a sticky note, but someone threw it out.

# However, they do remember a few key facts about the password:

#     It is a six-digit number.
#     The value is within the range given in your puzzle input.
#     Two adjacent digits are the same (like 22 in 122345).
#     Going from left to right, the digits never decrease; they only ever increase or stay the same (like 111123 or 135679).

# Other than the range rule, the following are true:

#     111111 meets these criteria (double 11, never decreases).
#     223450 does not meet these criteria (decreasing pair of digits 50).
#     123789 does not meet these criteria (no double).

# How many different passwords within the range given in your puzzle input meet these criteria?

# Your puzzle input is 134564-585159.

# --- Part Two ---

# An Elf just remembered one more important detail: the two adjacent matching digits are not part of a larger group of matching digits.

# Given this additional criterion, but still ignoring the range rule, the following are now true:

#     112233 meets these criteria because the digits never decrease and all repeated digits are exactly two digits long.
#     123444 no longer meets the criteria (the repeated 44 is part of a larger group of 444).
#     111122 meets the criteria (even though 1 is repeated more than twice, it still contains a double 22).

# How many different passwords within the range given in your puzzle input meet all of the criteria?


import time # you know, for some fun
password_count = 0
password_list = []

for every in range(134564, 585159):
    stringy = str(every)
    if (stringy[0]==stringy[1] and stringy[2] != stringy[1]) or (stringy[1]==stringy[2] and stringy[0] != stringy[1] and stringy[3] != stringy[2]) or (stringy[2]==stringy[3] and stringy[1] != stringy[2] and stringy[4] != stringy[3]) or (stringy[3]==stringy[4] and stringy[2] != stringy[3] and stringy[5] != stringy[4]) or (stringy[4]==stringy[5] and stringy[3] != stringy[4]):
        if stringy[0]<=stringy[1:5] and stringy[1]<=stringy[2:5] and stringy[2]<=stringy[3:5] and stringy[3]<=stringy[4:5] and stringy[4] <= stringy[5]:
            password_count += 1
            password_list.append(every)
print(f'{password_count} possible passwords in range.')
time.sleep(1)
print('...Cultivating List...')
time.sleep(1)
print(password_list)

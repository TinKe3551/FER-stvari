s = input()

s = int(s[1])
if s > 2: s -= 1
s -= 1
if s == 0: s = 4

print(hex(s * 90)[2:].upper())

import os

os.chdir("rezultati")

d = os.listdir()
n = 0

for i in range(1, len(d) + 1):

    f = open(f"output{i}").read().strip().split("\n")[-1]

    # print(f)

    if f != f"Files rezultati/output{i} and lab4_primjeri/test{i}/test.out are identical":
        n += 1
        print(f"output{i}")

print(1 - n / len(d), n)
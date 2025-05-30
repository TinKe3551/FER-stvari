import os

os.chdir("rezultati")

d = os.listdir()
n = 0

for i in range(1, len(d) + 1):

    f = ' '.join(open(f"output{i}").read().strip().split(" ")[-2:])

    # print(f)

    if f != f"are identical":
        n += 1
        print(f"output{i}")

print(f"{100 * (1 - n / len(d))} % riješenosti, {n} netočnih primjera")
from random import randrange

n = int(input("broj pravokutnika: "))
l = int(input("granica za x i y: "))

tocke = set()
max_x = 0
max_y = 0

dat = open("input", "w")
dat.write(str(n) + '\n')

for i in range(n):

    x1 = randrange(1, l)
    y1 = randrange(1, l)
    x2 = randrange(x1, l)
    y2 = randrange(y1, l)

    max_x = max(max_x, x2)
    max_y = max(max_y, y2)

    dat.write(f"{x1} {y1} {x2} {y2}\n")

dat.close()

    

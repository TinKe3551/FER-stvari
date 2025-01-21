from random import randrange, random

def gen_testcase(n, r = 0.5):
    k = randrange(2, n + 1)
    graf_txt = open("graf.txt", 'w')
    graf_txt.write(str(n) + '\n' + str(k) + '\n')
    a = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            l = random()
            if l < r: l = 1
            else: l = 0
            a[i][j] = l
            a[j][i] = l
        graf_txt.write(''.join(str(j) for j in a[i]) + '\n')
    for i in a:
        print(i)


if __name__ == '__main__':
    n = int(input("koliko vrhova u grafu: "))
    r = float(input("ucestalost jedinica u grafu (broj na intervalu [0, 1]): "))
    gen_testcase(n, r)
        



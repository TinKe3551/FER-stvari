n = int(input())

sirina = len(str(n))

for i in range(1, n + 1):
    isp = str(i)
    print((sirina - len(isp)) * '0' + isp)
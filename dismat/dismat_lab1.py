def umnozak_polinoma(pol1: dict, pol2: dict):

    pol3 = dict()

    for i in pol1:

        for j in pol2:

            pol3.setdefault(i + j, 0)
            pol3[i + j] += pol1[i] * pol2[j]

    return pol3


def binom_koef(n, k):

    r = 1

    k1, k2 = k, n - k
    if k1 < k2: k1, k2 = k2, k1

    for i in range(k1 + 1, n + 1):
        r *= i

    for i in range(2, k2 + 1):
        r //= i

    return r


def main():

    cajevi = ["Bohea", "Congou", "Souchong", "Singlo", "Hyson"]
    slova = "abcdef"

    vrste = 5
    
    parametri = []
    polinom = {0:1} # potencija:koeficijent
    for i in range(vrste):
        
        parametri.append(int(input(f"Unesite broj vrećica čaja {cajevi[i]} (parametar {slova[i]}): ")))
            

    n = int(input("Unesite broj n: "))
    for i in range(len(parametri)):
        if parametri[i] < 0:
            parametri[i] = n + 999
        polinom = umnozak_polinoma(polinom, {0:1, parametri[i] + 1:-1})

    if sum([n if i < 0 else i for i in parametri]) < n:
        print("Nije moguće napraviti nijednu čajanku")
        return 0

    cajanke = 0

    for p in polinom:
        cajanke += polinom[p] * binom_koef(n - p + vrste - 1, n - p)

    print("Broj mogućih čajanki:", cajanke)
        


main()

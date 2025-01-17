# kodiranje poruke metodom LZW
message = 3 * "abcdef"
D = ['\0', 'a', 'b', 'c', 'd', 'e', 'f']
coded_lzw = encode_lzw(D, message)

# usporedba duljina kodirane poruke (LZ77 i LZW)

print("-------- LZW --------")
print("dictionary =", D)
print("code length =", len(coded_lzw))
print("code:", coded_lzw)
print()


lz77_params = [
    (len(message), len(message)),
    (8, 10),
    (4, 3),
    (3, 3)
]

print("-------- LZ77 --------")
for sb, la in lz77_params:
    
    coded_lz77 = encode_lz77(message, sb, la)

    print("search buffer =", sb)
    print("look ahead buffer =", la)
    print("code length (triples) =", len(coded_lz77))
    print("code:", coded_lz77)


# - metoda LZW daje kraću kodiranu poruku nego metoda LZ77
# - kodirana poruka dobivena algoritmom LZW sadrži 12 brojeva, dok
# (najkraća) kodirana poruka dobivena algoritmom LZ77 sadrži 7 trojki,
# odnosno 21 brojeva/simbola

# - metoda LZW daje kraće kodove jer koristi unaprijed zadan rječnik
# - ako se ista poruka kodira uz isti početni rječnik, taj rječnik će
# se proširivati na isti način
# - za kodiranu poruku dovoljno je da sadrži indekse simbola 
# (ili niza simbola) u rječniku
# - radi uspješnog kodiranja pošiljatelj i primatelj trebaju imati isti
# početni riječnik pri kodiranju/dekodiranju poruke

# - metoda LZ77 daje dulje kodove jer koristi dio poruke koju kodira
# kao rječnik
# - kodirana poruka mora sadržavati više informacija o pojedinom dijelu
# originalne poruke
# - radi uspješnog kodiranja, pošiljatelj i primatelj ne moraju
# poduzimati dodatne predkorake

##Deseti zadatak
##--------------------
#Prvi podatci
X = ['1', '2', '3', '4', '5']
F_X = np.array([6, 4, 5, 5, 6])

#Shannon-Fano kodovi
x_fx_sorted = sorted(zip(range(len(X)), X, F_X), key=lambda x: x[2], reverse=True)
order, X_sorted, F_X_sorted = zip(*x_fx_sorted)
C_X_sf = [''] * len(X_sorted)
shannon_fano_code(F_X_sorted, C_X_sf, 0, len(X_sorted) - 1)
sf_codes = dict(zip(X_sorted, C_X_sf))

#Huffmanovi kodovi
x_fx_dict = dict(zip(X_sorted, F_X_sorted))
heap = dict_to_nodes(x_fx_dict)
heapq.heapify(heap)
root = huffman_code(heap)
huff_codes = get_codes(root)

#Izračun prosječne duljine riječi
total_frequency = sum(F_X_sorted)
avg_length_sf = sum(len(sf_codes[symbol]) * freq for symbol, freq in zip(X_sorted, F_X_sorted)) / total_frequency
avg_length_huff = sum(len(huff_codes[symbol]) * freq for symbol, freq in zip(X_sorted, F_X_sorted)) / total_frequency

#Izračun entropije i efikasnosti
probabilities = F_X_sorted / total_frequency
entropy = -np.sum(probabilities * np.log2(probabilities))
efficiency_sf = entropy / avg_length_sf
efficiency_huff = entropy / avg_length_huff

#Rezultati
print("Primjer kada su kodovi jednako efikasni:\n")
print("Shannon-Fano kodovi:", sf_codes)
print("Huffman kodovi:", huff_codes)
print("\nProsječna duljina kodne riječi:")
print("Shannon-Fano:", avg_length_sf)
print("Huffman:", avg_length_huff)
print("\nEfikasnost koda:")
print("Shannon-Fano:", efficiency_sf)
print("Huffman:", efficiency_huff)

#Provjera
print("\nOptimalnost:")
if entropy <= avg_length_sf < entropy + 1:
    print("Shannon-Fano kod je optimalan.")
else:
    print("Shannon-Fano kod nije optimalan.")

if entropy <= avg_length_huff < entropy + 1:
    print("Huffman kod je optimalan.")
else:
    print("Huffman kod nije optimalan.")

#Drugi podatci
X = ['1', '2', '3', '4', '5']
F_X = np.array([42, 21, 15, 15, 12])

#Shannon-Fano kodovi
x_fx_sorted = sorted(zip(range(len(X)), X, F_X), key=lambda x: x[2], reverse=True)
order, X_sorted, F_X_sorted = zip(*x_fx_sorted)
C_X_sf = [''] * len(X_sorted)
shannon_fano_code(F_X_sorted, C_X_sf, 0, len(X_sorted) - 1)
sf_codes = dict(zip(X_sorted, C_X_sf))

#Huffmanovi kodovi
x_fx_dict = dict(zip(X_sorted, F_X_sorted))
heap = dict_to_nodes(x_fx_dict)
heapq.heapify(heap)
root = huffman_code(heap)
huff_codes = get_codes(root)

#Izračun prosječne duljine riječi
total_frequency = sum(F_X_sorted)
avg_length_sf = sum(len(sf_codes[symbol]) * freq for symbol, freq in zip(X_sorted, F_X_sorted)) / total_frequency
avg_length_huff = sum(len(huff_codes[symbol]) * freq for symbol, freq in zip(X_sorted, F_X_sorted)) / total_frequency

#Izračun entropije i efikasnosti
probabilities = F_X_sorted / total_frequency
entropy = -np.sum(probabilities * np.log2(probabilities))
efficiency_sf = entropy / avg_length_sf
efficiency_huff = entropy / avg_length_huff

#Rezultati
print("Primjer kada kodovi nisu jednako efikasni:\n")
print("Shannon-Fano kodovi:", sf_codes)
print("Huffman kodovi:", huff_codes)
print("\nProsječna duljina kodne riječi:")
print("Shannon-Fano:", avg_length_sf)
print("Huffman:", avg_length_huff)
print("\nEfikasnost koda:")
print("Shannon-Fano:", efficiency_sf)
print("Huffman:", efficiency_huff)

#Provjera
print("\nOptimalnost:")
if entropy <= avg_length_sf < entropy + 1:
    print("Shannon-Fano kod je optimalan.")
else:
    print("Shannon-Fano kod nije optimalan.")

if entropy <= avg_length_huff < entropy + 1:
    print("Huffman kod je optimalan.")
else:
    print("Huffman kod nije optimalan.")

##Jedanaesti zadatak
##-----------------------    
X = ['a', 'b', 'c', 'd']
P_X = np.array([0.4, 0.3, 0.2, 0.1])
message = 'abcdcdd'

#Shannon-Fano kodiranje
x_fx_pairs = list(zip(X, P_X))
x_fx_sorted = sorted(x_fx_pairs, key=lambda x: x[1], reverse=True)
X_sorted, P_X_sorted = zip(*x_fx_sorted)
C_X_shannon = [''] * len(X_sorted)
shannon_fano_code(P_X_sorted, C_X_shannon, 0, len(X_sorted) - 1)
shannon_dict = dict(zip(X_sorted, C_X_shannon))
shannon_encoded = ''.join(shannon_dict[symbol] for symbol in message)
shannon_length = len(shannon_encoded)

#Huffman kodiranje
x_fx_dict = dict(zip(X, P_X))
heap = dict_to_nodes(x_fx_dict)
heapq.heapify(heap)
root = huffman_code(heap)
huffman_dict = get_codes(root)
huffman_encoded = ''.join(huffman_dict[symbol] for symbol in message)
huffman_length = len(huffman_encoded)

#Aritmetičko kodiranje
arithmetic_code = encode_arithmetic(message, X, P_X)
arithmetic_length = -np.log2(arithmetic_code)

#Ispis rezultata
print("Rezutati:\n")
print("Shannon-Fano kodirano:", shannon_encoded, "Duljina:", shannon_length)
print("Huffman kodirano:", huffman_encoded, "Duljina:", huffman_length)
print("Aritmetički kodirano:", arithmetic_code, "Duljina:", arithmetic_length)
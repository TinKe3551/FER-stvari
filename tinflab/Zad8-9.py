---------------------------------------------------------------------------------------------------------------
Zad 8.1.
---------------------------------------------------------------------------------------------------------------
import numpy as np

def shannon_fano_code(probabilities_sorted, codes, start, end):
    if start == end:
        return
    l = start
    r = end
    sum_left, sum_right = 0, 0
    while l <= r:
        if sum_left <= sum_right:
            sum_left += probabilities_sorted[l]
            l += 1
        else:
            sum_right += probabilities_sorted[r]
            r -= 1
    for i in range(start,l):
        codes[i] += '0'
    for i in range(l,end+1):
        codes[i] += '1'
        
    shannon_fano_code(probabilities_sorted, codes, start, l-1)
    shannon_fano_code(probabilities_sorted, codes, l, end)

    
## example run
X = ['1','2','3','4','5']
F_X = np.array([14, 7, 5, 5, 4])

# reversed sorting symbol-probability pairs with respect to probabilities
x_fx_pairs = zip(range(len(X)), X, F_X)
x_fx_sorted = sorted(x_fx_pairs, key = lambda x: x[2], reverse = True)
print("Symbol-frequency pairs sorted wrt. frequency:")
for x_fx in x_fx_sorted:
    print("x{0} = {1}, f(x{0}) = {2}".format(x_fx[0], x_fx[1], x_fx[2]))
    
# call encode_shannon_fano function
order, X, F_X = zip(*x_fx_sorted)
C_X = ['']*len(X)
shannon_fano_code(F_X, C_X, 0, len(X)-1)
x_cx_dict = dict(zip(X,C_X))
print("\nSymbol-code pairs:")
for x, cx in x_cx_dict.items():
    print(x, "-", cx)
	
---------------------------------------------------------------------------------------------------------------
Zad 8.2.
---------------------------------------------------------------------------------------------------------------

# (a) prosječna (srednja) duljina kodne riječi
A = 0
for i in range(len(F_X)):
    A += F_X[i]
L_X = 0
for i in range(len(F_X)):
    L_X += (len(C_X[i]) * F_X[i]) / A

print("Prosječna duljina kodne riječi: " + str(L_X))

# (b) efikasnost koda
H_X = 0
for i in range(len(F_X)):
    H_X -= (F_X[i]/A) * np.log2(F_X[i]/A)
    
e = H_X / L_X
print("Efikasonost koda: " + str(e))

# (c) optimalnost koda

if (H_X <= L_X) and (L_X <= H_X + 1):
    print("Kod je optimalan.")
else:
    print("Kod nije optimalan.")
	
---------------------------------------------------------------------------------------------------------------
Zad 9.1.
---------------------------------------------------------------------------------------------------------------

class Node:
    def __init__(self, symbol, probability):
        self.symbol = symbol
        self.probability = probability
        self.left = None
        self.right = None
    def __repr__(self):
        return ("(x="+str(self.symbol)+", p(x)="+str(self.probability)+")")
    @property
    def __lt__(self, other):
        return self.probability < other.probability
    def __gt__(self, other):
        return self.probability  > other.probability

def dict_to_nodes(probabilities):
    nodes = []
    for symbol in probabilities.keys():
        nodes.append(Node(symbol,probabilities[symbol]))
    return nodes

def get_codes(root, codeword="", codes_dict={}):
    #given the root of the Huffman code tree, traverses the tree and returns the code of every symbol
    if root.left == None and root.right == None:
        codes_dict[root.symbol] = codeword
    else:
        if root.left != None:
            get_codes(root.left, codeword+"0", codes_dict)
        if root.right != None:
            get_codes(root.right, codeword+"1", codes_dict)
    return codes_dict

def huffman_code(heap):
    #construct Huffman code tree given nodes in the heap
    while len(heap) > 1:
        edge1 = heapq.heappop(heap)
        edge2 = heapq.heappop(heap)
        node = Node("x",edge1.probability+edge2.probability)
        node.left = edge1
        node.right = edge2
        heapq.heappush(heap, node)
    root = heapq.heappop(heap)
    return root        #if heap only contains 1 node, that node is root. 

x_fx_dict = dict(zip(X,F_X))
heap = dict_to_nodes(x_fx_dict)
# print(heap)
heapq.heapify(heap) 
root = huffman_code(heap) 
x_cx_dict = get_codes(root)
print("\nSymbol-code pairs:")
for x, cx in x_cx_dict.items():
    print(x, "-", cx)
	
---------------------------------------------------------------------------------------------------------------
Zad 9.2.
---------------------------------------------------------------------------------------------------------------

# (a) prosječna duljina kodne riječi

total_frequency = sum(F_X)
average_length = sum(len(code) * freq for code, freq in zip(x_cx_dict.values(), F_X)) / total_frequency

print("Prosječna duljina kodne riječi:", average_length)

# (b) efikasnost koda

probabilities = F_X / total_frequency
entropy = -np.sum(probabilities * np.log2(probabilities))
efficiency = entropy / average_length
print("Efikasnost koda:", efficiency)

# (c) optimalnost koda

if entropy <= average_length < entropy + 1:
    print("Kod je optimalan.")
else:
    print("Kod nije optimalan.")
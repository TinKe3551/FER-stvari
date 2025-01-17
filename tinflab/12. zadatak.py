##message = "abcdefabcdefabcdef"
##
##search_buffer = range(4, 18)
##search_buff_look_ahead_buff_diff = [1,2,3,4]
##
##coded_length = []
##
##for sb in search_buffer:
##    look_ahead_buffer = sb - 1
##    coded = encode_lz77(message, sb, look_ahead_buffer)
##    print("sb={}, coded:{}".format(sb,coded))
##    coded_length.append(len(coded))
##        
##
##plt.plot(search_buffer, [len(message)]*len(search_buffer), 'red')
##plt.plot(search_buffer, coded_length)
##
##plt.xlabel("search buffer size")
##plt.ylabel("message length")
##plt.legend(["original msg","coded message"])


def la_diff_code_lengths(sb_range, la_diff, msg):
    
    code_lengths = []

    for sb in sb_range:
        
        la = sb - la_diff
        coded = encode_lz77(msg, sb, la)
        
        print("search buffer =", sb)
        print("look ahead buffer =", la)
        print("coded message length (in triples) =", len(coded))
        print("coded message:", coded)
        print()
        
        code_lengths.append(len(coded))

    return code_lengths


def color_from_num(n):
    color = hex(n % int("ffffff", 16))[2:]
    color = '#' + (6 - len(color)) * '0' + color
    return color


message = "abcdefabcdefabcdef"

search_buffer = range(4, 18)
search_buff_look_ahead_buff_diff = list(range(-3, 4))

legend = ["original msg"]
plt.plot(search_buffer, [len(message)]*len(search_buffer), '#000000')

colornum = 2560
d = (int("ffffff", 16) - 2560) // (len(search_buff_look_ahead_buff_diff) + 1)

for la_diff in search_buff_look_ahead_buff_diff:
    
    colornum += d
    colornum %= int("ffffff", 16)
    
    plt.plot(search_buffer, la_diff_code_lengths(search_buffer, la_diff, message), color_from_num(colornum))

    if la_diff > 0:
        legend.append("la = sb - " + str(la_diff))
    elif la_diff < 0:
        legend.append("la = sb + " + str(-la_diff))
    else:
        legend.append("la = sb")


plt.xlabel("search buffer size")
plt.ylabel("message length")
plt.legend(legend)


# u većem posmičnom prozoru nalazi se veći broj uzoraka koji su 
# potencijalno jednaki uzorku na početku prozora za kodiranje,
# zbog čega povećanje posmičnog prozora povećava efikasnost kodiranja

# povećanjem prozora za kodiranje povećava se maksimalna duljina uzorka 
# koji se potencijalno može naći u posmičnom prozoru, a to doprinosi
# većoj efikasnosti kodiranja

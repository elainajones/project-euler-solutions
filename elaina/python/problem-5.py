
num=20
div_list = range(2,20)[::-1]

while True:
    even_div = True
    for i in div_list:
        if num % i != 0:
            even_div = False
            break

    if even_div:
        break
    else:
        num+=20

print(num)

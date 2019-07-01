# Erro no código
def max(a, b):
    if(a > b):
        return a
    else:
        return b

size = int(input())
hight = []
minleft = []
minright = []
mindef = []

sub = 0

for i in range(size):
    v = int(input())
    hight.append(v)
minleft[0] = hight[0]

for i in range(1, size, 1):
    minleft[i] = max(minleft[i - 1], hight[i])
minright[size - 1] = hight[size - 1]

for i in range(size - 2, 0, 1):
    minright[i] = max(minright[i + 1], hight[i])

for i in range(size):
    mindef[i] = -max(-minright[i], -minleft[i])

for i in range(size):
    if mindef[i] > hight[i]:
        sub += 1

print(sub)
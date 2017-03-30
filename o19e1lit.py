ile = int(raw_input())

jas = str(raw_input())
mal = str(raw_input())

licznik = 0

def lacz(a=[],b=[]):
    global licznik
    suma = []
    indA=0
    indB=0
    while indA<len(a) or indB<len(b):
        if indA>=len(a):
            suma.append(b[indB])
            indB+=1
        else:
            if indB>=len(b):
                suma.append(a[indA])
                indA+=1
                licznik+=indB
            else:
                if a[indA]<b[indB]:
                    suma.append(a[indA])
                    indA+=1
                    licznik+=indB
                else:
                    suma.append(b[indB])
                    indB+=1
    return suma


def sortuj(a=[]):
    dlug = len(a)
    if dlug==1:
        return a
    return lacz(sortuj(a[:dlug/2]),sortuj(a[dlug/2:]))

alfabet = [[] for i in xrange(26)]

for i in xrange(ile-1,-1,-1):
    litera = mal[i]
    alfabet[ord(litera)-ord('A')].append(i)

perma = []
for i in xrange(ile):
    litera = jas[i]
    perma.append(alfabet[ord(litera)-ord('A')].pop())

sortuj(perma)
print licznik

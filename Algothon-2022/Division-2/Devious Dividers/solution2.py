line = input()
line.split(" ")
h = int(line.split(" ")[0])
w = int(line.split(" ")[1])

widthDividers = []
heightDividers = []

line = input().split(" ")
dw = int(line[0])
for i in range(dw):
    widthDividers.append(int(line[i+1]))

line = input().split(" ")
dh = int(line[0])
for i in range(dh):
    heightDividers.append(int(line[i+1]))

heightDividers.append(h)
widthDividers.append(w)
widthDividers.sort()
heightDividers.sort()

distH = [heightDividers[0]]
distW = [widthDividers[0]]
for i in range(1, len(widthDividers)):
    distW.append(widthDividers[i] - widthDividers[i-1])
for i in range(1, len(heightDividers)):
    distH.append(heightDividers[i] - heightDividers[i-1])

distW.sort(reverse=True)
distH.sort(reverse=True)

divW = max(distW[0]/2, distW[1]) * distH[0]
divH = max(distH[0]/2, distH[1]) * distW[0]

print("{:.1f}".format(min(divW, divH)))

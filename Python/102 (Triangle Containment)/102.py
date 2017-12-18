# Alex Slater 102
#This method uses the fact the origin lies inside the triangle if and only if it lies on the same side of each line as the other vertex.

triangles = []

#Checks to see if the origin is on the same side of the line as (x3, y3)
#There are no degenerate triangles, no vertical lines or no triangles with the oginin on the edge, no no special case handling required
def checkLine(x1, y1, x2, y2, x3, y3):
    p3 = (y3-y1)*(x2-x1) - (x3-x1)*(y2-y1)
    origin = (0-y1)*(x2-x1) - (0-x1)*(y2-y1)

    if (p3>0 and origin>0) or (p3<0 and origin<0):
        return True

    return False

#Get our triangles from the text file
with open("triangles.txt") as f:
    for s in f:
        triangles.append((s.replace('\n', '')).split(','))

#Tests if the origin lies inside each triangle and finds the number of them
s = 0
for t in triangles:
    t = [int(i) for i in t]
    if checkLine(t[0], t[1], t[2], t[3], t[4], t[5]) and checkLine(t[2], t[3], t[4], t[5], t[0], t[1]) and checkLine(t[4], t[5], t[0], t[1], t[2], t[3]):
        s += 1

print(s)

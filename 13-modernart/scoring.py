from math import exp

score = int(input())

LO = 6000
HI = 7300

#print(((score - LO)/(HI - LO))**2 )

print(exp(0.002 * (score-7300)))

# 7239: handpick after visualiser thingo
# 7105: startfull
# 7064: naive then improver
# 6897: naive
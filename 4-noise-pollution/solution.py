# Ryan
N = int(input())
loudests = {}
for rep in range(N):
        person, loudness, numSports = input().split()
        loudness = int(loudness)
        numSports = int(numSports)
        sports = [input() for _ in range(numSports)]
        
        for sport in sports:
                if sport not in loudests or loudness > loudests[sport][0]:
                        loudests[sport] = (loudness, person)
                        
for sport, (loudness, person) in sorted(loudests.items()):
        print(f"In {sport}, {person} is the loudest!")

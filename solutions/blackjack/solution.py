n = int(input())
card = []
<<<<<<< HEAD

for i in range(n):
    card1,card2 = input(), input()
    card.append([card1, card2])

=======
for i in range(n):
    card1,card2 = input(), input()
    card.append([card1, card2])
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
def score_cal(cards):
    points = 0
    index = 0

    for i in cards:
        if i == 'Queen' or i == 'King' or i == 'Jack':
            i = 10
        if i == 'Ace':
            k = [11,1]
            pts = dict(zip(k, [None]*len(k)))

            for v in k:
                cards_int = [v if i =='Ace' else i for i in cards]
                cards_int = [10 if i == 'Queen' or i == 'King' or i == 'Jack' else i for i in cards_int]
                point = sum(int(x) for x in cards_int)     

                if int(point) >= 16 and int(point) <= 21:
                    pts[v] = int(point)
                elif int(point)>=21:
                    pts[v] = 0
                elif int(point)<=16:
                    pts[v] = 1
<<<<<<< HEAD

=======
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
            i = max(pts, key=pts.get)
        else:
            i = int(i)

        points += i
        index += 1
<<<<<<< HEAD

    return points

point = []

=======
    return points
point = []
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
for i in card:
    index = card.index(i)
    points = score_cal(i)
    point.append(points)

if any(i==21 for i in point):
    for i in point:
        if i==21:
            no = point.index(i) + 1
            print('Player', no, 'has Black Jack!')
        else:
            continue
<<<<<<< HEAD

        break
=======
        break;
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
else:
    for i in card:
        index = card.index(i)
        pts = point[index]
        index_pt = point.index(pts)
        a = 2
<<<<<<< HEAD

=======
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
        while pts < 18 and a < 5:
            new_card = input()
            i.append(new_card)
            new_point = score_cal(i)
            pts = new_point
            a += 1
<<<<<<< HEAD

        point[index_pt] = pts

    converted_point = []

=======
        point[index_pt] = pts
    converted_point = []
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
    for i in point:
        if i > 21 or i <16:
            converted_point.append(0)
        else:
            converted_point.append(i)
<<<<<<< HEAD

=======
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6
    if any(len(i) == 5 for i in card):
        for i in card:
            if len(i) == 5:
                no = card.index(i) +1    
                print('Player',no,'has 5-card Charlie')
<<<<<<< HEAD
                break
            else:
                continue

    else:
        rank = sorted(range(len(converted_point)), key=lambda k: converted_point[k], reverse = True)
        
        for i in rank:
            no = i + 1
            card_drew = ' '.join(card[i])
            print('Player',no,card_drew)
=======
                break;
            else:
                   continue
    else:
        rank = sorted(range(len(converted_point)), key=lambda k: converted_point[k], reverse = True)
        for i in rank:
            no = i + 1
            card_drew = ' '.join(card[i])
            print('Player',no,card_drew)
>>>>>>> bdb88bdcb354f83fd5cf5dc800c7d5926797b3c6

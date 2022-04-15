#!/usr/bin/env python
# coding: utf-8

# In[17]:

import pandas as pd
import numpy as np


# In[18]:

card_list = [2,3,4,5,6,7,8,9,10,'Jack','Queen','King', 'Ace']


# In[20]:

n = int(input())


# In[28]:

draw = pd.DataFrame()
no = 1
for i in range(n):
    player = 'Player ' + str(no)
    card1,card2 = input(), input()
    draw[player] = card1, card2
    no += 1


# In[29]:

#Preparing DataSet
draw = draw.T
draw[[2,3,4]] = 0


# In[31]:

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
                else:
                    pts[v] = 0
            i = max(pts, key=pts.get)
        else:
            i = int(i)
        points += i
        index += 1
    return points


# In[32]:

for index, cards in draw.iterrows():
    points = score_cal(draw.loc[index,[0,1]])
    draw.loc[index,'sum1'] = points
    
    if points == 21:
        break

# In[33]:

draw['sum2'] = 0
for index, row in draw.iterrows():
    point = row['sum1']
    a = 2
    while point < 18 and a < 5:
        draw.loc[index, a] = input()
        new_point = score_cal(draw.loc[index,[0,1,2,3,4]])
        point = new_point
        a += 1
    draw.loc[index,'sum2'] = point
    if draw.loc[index,'sum2'] > 21 or draw.loc[index,'sum2'] < 16:
        draw.loc[index,'converted_point'] = 0
    else:
        draw.loc[index,'converted_point'] = draw.loc[index, 'sum2']


# In[34]:

#Ranking
for index, rows in draw.iterrows():
    if rows['sum1'] == 21:
        print(index, ' ', 'has Black Jack!')
        break
    elif rows['sum2'] <= 21 and 0 not in rows.values:
        print(index, ' ', 'has 5-card Charlie')
        break
    else:
        draw = draw.sort_values(by = ['converted_point'], ascending = False)
        draw_result = draw[[0,1,2,3,4]]
        print(draw_result.to_string(header = False))
        break

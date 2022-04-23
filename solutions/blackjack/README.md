Challenge: Black Jack

Problem Statement: 
In this problem we will be following a closely modelled version of the real Black Jack game. Given  players and a deck of max 52 cards, 
each player is initially dealt 2 cards. The score of any player at any time is the 'sum' of each of their card scores. Cards of value 2-10 will be counted 
as their normal value. Jack, Queen, King will be counted as 10 and Ace can be counted as EITHER 11 or 1. If a player score is less than 18, the player 
may keep drawing. However, the player can never have more than 5 cards at any time. At the end, the score will be calculated from 16-21, and whoever is 
not in the range loses. Players are ranked depending on how high they score. However, there are two special cases:
(1) If in the first 2 cards, if someone scores exactly 21, the game stops and the person wins 
(2) if everyone is done drawing, and one player has 5 cards, AND their total score is between 16 and 21, then they will win the game.
Write a program to rank players on these rules.


Input Format:
Input should be number of players (integer), what cards each player are handed (2-10, Jack, Queen, King, Ace) , 
and output should be the cards of all players and the rankings 
Your first line of input should be the number of players (smaller than 5). 
Your following lines of input should be the top cards of the deck. 
Initially, each player will draw two cards in their order (e.g. Player 1 draws 2 cards, then Player 2 draws 2 cards etc.) 
If any player has total score of lower than 18, they will keep drawing until the game stops. 
You are guaranteed that the deck has enough cards for an outcome to happen before the deck runs out of cards.

Constraints:
Number of player (N) is smaller than 5
Number of times players draw the card is smaller or equal to 5 


Output Format:
If the special case (1) happens: 'Player _ has Black Jack!' If the special case (2) happens: 'Player _ has 5-card Charlie' 
Else, rank Player according to their scores and display their cards. If 2 players have the same score, the player who draw first will be ranked above 
(example: Player 1 and 2 score 18 so Player 1 will be ranked above Player 2). See sample cases for output format.


Sample cases:
Sample Input 0:
3
4
7
Ace
2
Queen
3
8
Queen
King
5

Sample Output 0

Player 1 4 7 8
Player 3 Queen 3 5
Player 2 Ace 2 Queen King
Explanation 0

There are 3 players Player 1 draw 4 and 7. Player 2 draw Ace and 2. Player 3 draw Queen and 3. 
Hence none of them score more than 18 so they need to keep drawing:

Player 1 draw 8 (score 19: stop drawing),

Player 2 draw third card as Queen (score 13), fourth card as King (score 23)

Player 3 draw 5 (score 18)



Sample Input 1

4
8
4
Ace
King
9
4
5
7
Sample Output 1

Player 2 has Black Jack!


Sample Input 2
3
4
8
9
3
5
3
Ace
7
4
5
3
6
2
Sample Output 2

Player 3 has 5-card Charlie
Explanation 2

There are 3 player Player 1: draw 4 and 8 (total 12) Player 2: draw 9 and 3 (total 12) 
Player 3: draw 5 and 3 (total 8) Hence, all 3 players need to keep drawing: 
Player 1: third card is Ace (total 13 since Ace is counted as 1 will be more favorable) forth card is 7 (total 20. end) 
Player 2: third card is 4 (total 16), forth card is 5 Player 3: third card is 3 (total 11), forth card is 6 (total 17), fifth card is 2 (total 19) 
So Player 3 has 5-card Charlie





# Exact Change 2  

Jack wants to pay for an item at the convenient store. However, this particular store does not give change, i.e., the amount you pay must be the exact price of the item you are buying, and only takes exactly three coins. Luckily, Jack brought a lot of coins. See if Jack can get the exact change for a given item price *p* he wants using exactly three coins.   

Complete the sumCoins function and return 1 if it's possible and 0 is it isn't.   
<br>

# Input Format 

The price of the item is given as an input *p*. All Jack's coins are given in an array *coins* with a given length of *n*.   
<br>

# Constraints  
The values of the *p* and all values in the array *coins* are positive. *n* will always be equal or larger than 3.   
<br>

# Output Format  
Return 1 if Jack can find the right combination of three coins. If he cannot, then return 0.   
<br>

# Sample Cases and Explanations  
## Testcase 1
**Input**
```
150
3
50
50
50
```
**Expected Output**
```
1
```
**Explanation**  
The price of the item was 1.50. There are three 50c coins so you can get 1.50 by choosing all three 50c coins.   

## Testcase 2
**Input**
```
400
6
50
10
20
10
100
200
```
**Expected Output**
```
0
```
**Explanation**   
There is no combination of three coins that add up to 4.   

## Testcase 3
**Input**
```
500
3
200
200
200
```
**Expected Output**
```
0
```
**Explanation**   
Even thought we can get more than 5 with our three 2 coins, it is not the exact change for 5 so we return 0.   
# nth Highest Test Score  

Bobby wants to find out his mark for a test he did. However, he only knows his ranking out of all the participants. Luckily, the organizers were kind enough to give him all the marks of all the participants. However, the marks are anonymous and unordered. 

Find Bobby's mark by completing the function findMark and returning and integer representing the mark.  
<br>

# Input Format 

All the marks are given in an unordered singly linked list, called marks, ended by a NULL. The mark for each student is given in the member definition.
```c
int data;
```
The format of each linked list node is:
```c
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};
```
where data are the given "marks" and "next" is the next node.
You are given the head of the linked list.
<br>

# Constraints  
``` marks < 0 ```   
There are less than 50 marks
<br>

# Output Format  
Return the mark as an int.   
<br>

# Sample Cases and Explanations  
## Testcase 1
**Input**
```
5
7
45
63
67
97
53
36
74
```
**Expected Output**
```
53
```
**Explanation**  
The first input is Bobby's rank. The second input is the number of marks given. The remaining inputs are the unordered scores. Since Bobby placed 5th, you must find the 5th highest score, which is 53.

## Testcase 2
**Input**
```
4
4
90
88
88
70
```
**Expected Output**
```
70
```
**Explanation**   
We are looking for the 4th highest number (first input). We know there are 4 marks given (second input). While 70 is not the 4th highest unique number, since there are two 88 marks 70 gets pushed down to the 4th highest mark.
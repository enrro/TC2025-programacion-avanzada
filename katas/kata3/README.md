# Kata 3: 657. Judge Route Circle

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to **the original place**.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L(Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Ejemplo 1:
```
Input: "UD"  Output: true  
```
Ejemplo 2:
```
Input: "LL"  Output: false  
```

## My solution. 

First of all this is a problem of going back to the starting point. since for the follow path to return to the starting point it needs to have the same amount of ups and downs as well as the same amount of left and rights I decided that the best way to keep track of this values was with a variable to store the movements in the x and y axis, in the implementation we can use an array or 2 variables, and since there are only two variables I opted for keeping 2 integer variables. The edge cases of my problem are when there are more movements in the x or y axis than there can be numbers in an integer. In this case the program fails.
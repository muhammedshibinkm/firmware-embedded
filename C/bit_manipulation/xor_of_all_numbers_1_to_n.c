/*Given a number n, the task is to find the XOR of every number from 1 to n. Why does the following algorithm work?
Find the remainder of n by moduling it with 4.
If rem = 0, then XOR will be same as n.
If rem = 1, then XOR will be 1.
If rem = 2, then XOR will be n+1.
If rem = 3, then XOR will be 0.
  */

/*
0⊕1=12⊕3=14⊕5=1⋯
ex:1 to 5

  0001
  0010
  0011
  0100
  0101
  ===========
  


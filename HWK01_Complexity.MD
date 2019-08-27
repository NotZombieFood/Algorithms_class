---
author: Gerardo Cruz Delgado
title: Complexity of recursive algorithms
hwk: 01
---

# Complexity of recursive algorithms
## 1. Find the computional complexity of the following 
### 1.1 T(N) = 3T(N/2) + N ^ 2
1.58 < 2
So T(N) =  Omega(N ^ 2) 
### 1.2 T(N) = 4T(N/2) + N ^ 2
c =2 
2 = 2 
So T(N) = Omega(N^2 log (N))
### 1.3 T(N) = -3T(N/3) + N 
There cant be negative calls, so this case doesnt exist
### 1.4 T(N) = 3T(N/2) + 2 ^ N
Since 2^N will be the dominant value.
1.58 < c
So T(N) = Omega(2 ^ N)
### 1.5 T(N) = 16T(N/4) + N 
c = 1
2 > 1
So T(N) =  Omega(N ^ 2) 

## 2. Write the pseudo code, of how it will look in the code in the following formulas
### 2.1 T(N) = 4T(N/4) + N ^ 3
recursiveFunction(int n){
 if (n<1){
     for number in n{
         for number2 in n{
            for number3 in n{
                print(number1+number2+number3)
            }
        }
     }
     break
 }
    recursiveFunction(n/4)
    recursiveFunction(n/4)
    recursiveFunction(n/4)
    recursiveFunction(n/4)
}
recursiveFunction(0)

### 2.2 T(N) = 2T(N/1) + N
recursiveFunction(int n){
 if (n<1){
     for number in n{
         print(number)
     }
     break
 }
    recursiveFunction(n/2)
    recursiveFunction(n/2)
}
recursiveFunction(0)

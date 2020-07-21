# 8 Queen And TSP (by A*)

## 8 Queen

State Space:- An 8X8 matrix with any arrangement of 8 queens, and only one queen in a row.  
Initial State:- No queen is on board.  

           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0
           0 0 0 0 0 0 0 0  
           
Transition Operator:- Add a new queen in an empty row.  
Goal state:- 8 Queens placed on the board such that all queens are in non-attacking position.  
Heuristic:- Number of queens that attack each other.  

## TSP
Traveling Sales Man Problem Using A* Algorithm.  
To Compile :- g++ tsp.cpp  
Run ./a.out  
Typical Input:-  
Enter no. of cities: 5  /*(the five cities are named starting from 0 to 4)*/  
Enter no. of connecting Roads:6  
Enter City1 City2 PathCost:       /*(cityINDEX<SPACE>cityINDEX<SPACE>cost) , Add each city in ATLEAST one edge */  
0 1 34
0 4 20
1 2 15
1 3 16
2 4 24
3 2 12  

Enter the initial City: 3   /*Any city from 0 to 4*/  

Output:-  
3->1->2->4->0->3->  
Cost 75  


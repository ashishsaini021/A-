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

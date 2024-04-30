# Goal

The goal of this project is to write conway's game of life in C.  
For the display I will try to use the incredible gfxlib (don't search it is not the one on the internet) created by my school.

# Data storage

I will store the map in an array of bytes (ie char) arrays to save space, I think I could have used bits but it is way easier to manipulate chars so I'll stick to that.  
Each byte will be decomposed (0 being the lsb):  
- 0 : The current value of the cell, 1 if alive 0 if dead.  
- 1 : A temporary value used during the calculation of the next generation of the map to hold the next value. Should be similar to 0 outside of the `evolve_map` function (not guaranteed).  
- 2-6 : Unused  
- 7 : 1 if the cell is part of the map, 0 either.  

# Rules 

For a space that is populated:  
- Each cell with one or no neighbors dies, as if by solitude.  
- Each cell with four or more neighbors dies, as if by overpopulation.  
- Each cell with two or three neighbors survives.    

For a space that is empty or unpopulated:  
- Each cell with three neighbors becomes populated.  

# Algorithm 



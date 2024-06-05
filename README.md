# Labyrinth
The task is to create a random maze and save it. A maze solver can then load the maze and search for a way from S to E. 
A created maze will look like this

## Create Maze
W W W W W W W W W W W W W W W W W W W W 
W W W W X X X W X X X W X X X X X X X W 
W W W W X W X X X W X W X W X W X W X W 
W W W W X X W X W X X W X W X X X X X W 
W W W W W X W X W W X X X X W X W W X W 
W W W W W X X X W W X W W X X X X X X W 
W W W W X X W X W W X X X W W X W W X W 
W W X X X W X X X W X W X W W X X X X W 
W X X W X W X W E X X W X X X W X W X W 
W X W X X W X X W W X X X W X W S X X W 
W X X X W X X W X X X W W X X X W W X W 
W W W X X X W X W W X X X X W X W W X W 
W W W W W X X X X X X W W X W X W W X W 
W W W W W X W W X W W W X X X X W W X W 
W W W W W X X X X X X X X W W X X W X W 
W W W W W X W W X W W X W W W W X X X W 
W W W W W X W W X X X X W W X X X W X W 
W W W W W X W X X W W X X W X W X W X W 
W W W W W X X X W W W W X X X X X X X W 
W W W W W W W W W W W W W W W W W W W W

It is a 20x20 maze where 'W' = wall, 'X' = path, 'S'=start and 'E'=end

## Find Path in Maze

## Issues 
- It can hapens that no maze is created because of a stackoverflow 
- The finding of a solution is slow a other container might help. 

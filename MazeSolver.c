#include <stdio.h>
#include <stdbool.h>

bool WithinBoundary(int i, int j){
    return (i>=0 && i<=9 && j>=0 && j<=9);
}

bool CanGoLeft(int maze[10][10], int i, int j, int visited[10][10]){
    return (WithinBoundary(i-1, j) && maze[i-1][j] == 0 && visited[i-1][j] == 0);
}

bool CanGoRight(int maze[10][10], int i, int j, int visited[10][10]){
    return (WithinBoundary(i+1, j) && maze[i+1][j] == 0 && visited[i+1][j] == 0);
}

bool CanGoUp(int maze[10][10], int i, int j, int visited[10][10]){
    return (WithinBoundary(i, j-1) && maze[i][j-1] == 0 && visited[i][j-1] == 0);
}

bool CanGoDown(int maze[10][10], int i, int j, int visited[10][10]){
    return (WithinBoundary(i, j+1) && maze[i][j+1] == 0 && visited[i][j+1] == 0);
}

    

bool MazeSolver(int maze[10][10], int i, int j, int visited[10][10]){
    if (!WithinBoundary(i, j))
        return false;
    
    if (!CanGoLeft(maze, i, j, visited) &&
        !CanGoRight(maze, i, j, visited)&&
        !CanGoUp(maze, i, j, visited)   &&
        !CanGoDown(maze, i, j, visited)){
            return (i==9 && j==9);
        }
    else{
        //puts("im in else clause");
        if (CanGoLeft(maze, i, j, visited)){
            //printf("trying maze[%d][%d]\n", i-1, j);           
            visited[i-1][j] = 1;
            if (MazeSolver(maze, i-1, j, visited)){
                printf("go to maze[%d][%d]\n", i-1, j);
                return true;
            }
        }

        if (CanGoRight(maze, i, j, visited)){
            //printf("trying maze[%d][%d]\n", i+1, j);           
            visited[i+1][j] = 1;
            if (MazeSolver(maze, i+1, j, visited)){
                printf("go to maze[%d][%d]\n", i+1, j);    
                return true;
            }
        }

        if (CanGoUp(maze, i, j, visited)){
            //printf("trying maze[%d][%d]\n", i, j-1);           
            visited[i][j-1] = 1;
            if (MazeSolver(maze, i, j-1, visited)){
                printf("go to maze[%d][%d]\n", i, j-1);
                return true;
            }
        }

        if (CanGoDown(maze, i, j, visited)){
            //printf("trying maze[%d][%d]\n", i, j+1);           
            visited[i][j+1] = 1;
            if (MazeSolver(maze, i, j+1, visited)){
                printf("go to maze[%d][%d]\n", i, j+1);
                return true;
            }
        }
    }
    return false;
}

void SolveMaze(int maze[10][10]){
    
    int visited[10][10] = {{0}};
    
    bool t;
    t = MazeSolver(maze, 0, 0, visited);

    if (t)
        printf("true\n");
    else
        printf("false\n");
}








int main(void){
    int maze1[10][10] = {{0,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0}};

    int maze2[10][10] = {{0,0,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,1,1,1},
                         {1,0,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,1,1,1,1,1},
                         {1,1,1,0,0,1,1,1,1,1},
                         {1,1,0,0,0,1,1,1,1,1},
                         {1,0,1,1,0,1,1,1,1,1},
                         {1,0,1,1,0,0,0,1,1,1},
                         {1,0,1,1,1,1,0,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0}};


    SolveMaze(maze2);
    return 0;
} 

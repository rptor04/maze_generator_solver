#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000

int maze[HEIGHT][WIDTH];

// Directions
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void initMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;  // 1 represents walls
        }
    }
}

void carvePath(int x, int y) {
    maze[y][x] = 0;  // 0 represents open space

    // Randomly shuffle the directions
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int temp = directions[i];
        int randIndex = rand() % 4;
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }

    // Try to carve in the four directions
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[directions[i]] * 2;
        int ny = y + dy[directions[i]] * 2;

        if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT && maze[ny][nx] == 1) {
            maze[y + dy[directions[i]]][x + dx[directions[i]]] = 0;  // Remove wall between
            carvePath(nx, ny);  // Recursively carve
        }
    }
}

void printMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(maze[i][j] ? "# " : ". ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initMaze();
    carvePath(1, 1);  // Start carving from position (1,1)
    printMaze();
    return 0;
}


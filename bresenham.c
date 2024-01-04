#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

void drawLine(char canvas[HEIGHT][WIDTH], int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        canvas[y0][x0] = '*';

        if (x0 == x1 && y0 == y1) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// Function to display the canvas
void displayCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hi, I am Sanchar and this is Bresenham");
    printf("\n");
    
    char canvas[HEIGHT][WIDTH];

    // Initialize canvas
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Function call
    drawLine(canvas, 2, 2, 30, 10);

    // Display the canvas
    displayCanvas(canvas);

    return 0;
}

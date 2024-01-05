#include <stdio.h>

#define WIDTH 40
#define HEIGHT 20

void drawCircle(char canvas[HEIGHT][WIDTH], int xc, int yc, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        canvas[yc + y][xc + x] = '*';
        canvas[yc + x][xc - y] = '*';
        canvas[yc - y][xc - x] = '*';
        canvas[yc - x][xc + y] = '*';

        canvas[yc - y][xc + x] = '*';
        canvas[yc - x][xc - y] = '*';
        canvas[yc + y][xc - x] = '*';
        canvas[yc + x][xc + y] = '*';

        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void displayCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Hi, I am Sanchar and this is Midpoint Circle Drawing\n");
    
    char canvas[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    drawCircle(canvas, 20, 10, 8);

    displayCanvas(canvas);

    return 0;
}

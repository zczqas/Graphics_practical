#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

void dda(char canvas[HEIGHT][WIDTH], int x0, int y0, int x1, int y1) {
    float dx = x1 - x0;
    float dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++) {
        int Xint = round(X);
        int Yint = round(Y);
        canvas[Yint][Xint] = '*';
        X += Xinc;
        Y += Yinc;
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
    printf("Hi, I am Sanchar and this is DDA\n");
    char canvas[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    int x0 = 0, y0 = 0, x1 = WIDTH - 1, y1 = HEIGHT - 1;

    dda(canvas, x0, y0, x1, y1);

    displayCanvas(canvas);

    return 0;
}

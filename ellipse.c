#include <stdio.h>

#define WIDTH 40
#define HEIGHT 20

void drawEllipse(char canvas[HEIGHT][WIDTH], int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;
    int a_sqr = a * a;
    int b_sqr = b * b;
    int two_a_sqr = 2 * a_sqr;
    int two_b_sqr = 2 * b_sqr;
    int four_a_sqr = 4 * a_sqr;
    int four_b_sqr = 4 * b_sqr;
    int d1 = b_sqr - a_sqr * b + 0.25 * a_sqr;
    int dx = two_b_sqr * x;
    int dy = two_a_sqr * y;

    while (dx < dy) {
        canvas[yc + y][xc + x] = '*';
        canvas[yc - y][xc + x] = '*';
        canvas[yc + y][xc - x] = '*';
        canvas[yc - y][xc - x] = '*';

        if (d1 < 0) {
            x += 1;
            dx += two_b_sqr;
            d1 += dx + b_sqr;
        } else {
            x += 1;
            y -= 1;
            dx += two_b_sqr;
            dy -= two_a_sqr;
            d1 += dx - dy + b_sqr;
        }
    }

    int d2 = b_sqr * (x + 0.5) * (x + 0.5) + a_sqr * (y - 1) * (y - 1) - a_sqr * b_sqr;

    while (y >= 0) {
        canvas[yc + y][xc + x] = '*';
        canvas[yc - y][xc + x] = '*';
        canvas[yc + y][xc - x] = '*';
        canvas[yc - y][xc - x] = '*';

        if (d2 > 0) {
            y -= 1;
            dy -= two_a_sqr;
            d2 += a_sqr - dy;
        } else {
            y -= 1;
            x += 1;
            dx += two_b_sqr;
            dy -= two_a_sqr;
            d2 += dx - dy + a_sqr;
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
    printf("Hi, I am Sanchar and this is Midpoint Ellipse Drawing\n");
    
    char canvas[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    drawEllipse(canvas, 20, 10, 15, 8);

    displayCanvas(canvas);

    return 0;
}

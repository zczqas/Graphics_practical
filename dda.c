#include <stdio.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

void dda(char canvas[HEIGHT][WIDTH], int x0, int y0, int x1, int y1) {
    float dx = x1 - x0;
    float dy = y1 - y0;

    // Calculate steps required for generating pixels, using maximum absolute value
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate increments in x & y for each step as floating-point values
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step, rounding or truncating to integers
    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++) {
        int Xint = round(X); // Or use floor() for truncation
        int Yint = round(Y);
        canvas[Yint][Xint] = '*';
        X += Xinc;
        Y += Yinc;
    }
}

// Function to display the canvas (unchanged)
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

    // Initialize canvas
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    int x0 = 0, y0 = 0, x1 = WIDTH - 1, y1 = HEIGHT - 1;

    // Function call
    dda(canvas, x0, y0, x1, y1);

    // Display the canvas
    displayCanvas(canvas);

    return 0;
}

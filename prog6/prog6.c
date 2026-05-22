#include <stdio.h>
#include <math.h>

#define ROWS 25
#define COLS 50

struct Circle
{
    int x;
    int y;
    int radius;
};

void initializeBuffer(char buffer[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            buffer[i][j] = ' ';
        }
    }
}

void drawCircle(char buffer[ROWS][COLS], struct Circle c)
{
    int i, j;
    int dx, dy;
    int distanceSquared;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            dx = j - c.x;
            dy = i - c.y;

            distanceSquared = dx * dx + dy * dy;

            if(distanceSquared >= c.radius * c.radius - c.radius &&
               distanceSquared <= c.radius * c.radius + c.radius)
            {
                buffer[i][j] = '*';
            }
        }
    }
}

void displayBuffer(char buffer[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}

struct Circle inputCircle()
{
    struct Circle c;

    printf("Enter center x: ");
    scanf("%d", &c.x);

    printf("Enter center y: ");
    scanf("%d", &c.y);

    printf("Enter radius: ");
    scanf("%d", &c.radius);

    return c;
}

int main()
{
    char buffer[ROWS][COLS];

    struct Circle c;

    c = inputCircle();

    initializeBuffer(buffer);

    drawCircle(buffer, c);

    displayBuffer(buffer);

    return 0;
}
#include "raylib.h"

#include "bubble.h"

void Bubble::move()
{
    x = x + GetRandomValue(-5, 5);
    y = y + GetRandomValue(-5, 5);
}

void Bubble::show()
{
    DrawEllipseLines(x, y, r, r, WHITE);
}

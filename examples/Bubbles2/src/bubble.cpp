#include "raylib.h"

#define RAYMATH_IMPLEMENTATION
#include "raymath.h"

#include "bubble.h"

Bubble::Bubble(int bubble_x, int bubble_y, int bubble_r)
{
    x = bubble_x;
    y = bubble_y;
    r = bubble_r; 
    is_clicked = false;
}

void Bubble::move()
{
    x = x + GetRandomValue(-2, 2);
    y = y + GetRandomValue(-2, 2);
}

void Bubble::show()
{
    if(is_clicked)
    {
        DrawEllipse(x, y, r, r, RED);
    }
    else
    {
        DrawEllipseLines(x, y, r, r, WHITE);
    }
}

void Bubble::change_colour()
{
    is_clicked = true;
}

bool Bubble::contains(float temp_x, float temp_y)
{
    int d = Vector2Distance({temp_x, temp_y}, {(float)x, (float)y});

    if(d < r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bubble::intersects(Bubble b)
{
    int d = Vector2Distance({static_cast<float>(x),static_cast<float>(y)}, {static_cast<float>(b.x), static_cast<float>(b.y)});

    return (d < r + b.r);
}
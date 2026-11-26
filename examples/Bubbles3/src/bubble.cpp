#include "raylib.h"

#define RAYMATH_IMPLEMENTATION
#include "raymath.h"

#include "bubble.h"

Bubble::Bubble(int bubble_x, int bubble_y, int bubble_r)
{
    x = bubble_x;
    y = bubble_y;
    r = bubble_r; 
}

void Bubble::move()
{
    x = x + GetRandomValue(-2, 2);
    y = y + GetRandomValue(-2, 2);
}

void Bubble::show()
{
    DrawEllipse(x, y, r, r, {static_cast<unsigned char>(fill), static_cast<unsigned char>(fill), static_cast<unsigned char>(fill), 100});
    DrawEllipseLines(x, y, r, r, {static_cast<unsigned char>(outline), static_cast<unsigned char>(outline), static_cast<unsigned char>(outline), 255});
}

void Bubble::change_colour(int _outline, int _fill)
{
    outline = _outline;
    fill = _fill;
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
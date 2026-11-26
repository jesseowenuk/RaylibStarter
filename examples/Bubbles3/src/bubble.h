#pragma once

class Bubble
{
public:
    int x;
    int y;
    int r;
    int outline;
    int fill;

    // Constructor
    Bubble(int bubble_x, int bubble_y, int bubble_r = 50);

    void move();
    void show();
    void change_colour(int outline, int fill);
    bool contains(float temp_x, float temp_y);
    bool intersects(Bubble b);

    bool operator == (const Bubble& b)
    {
        if(x == b.x && y == b.y && b.r == r && b.outline == outline && b.fill == fill)
        {
            return true;
        }

        return false;
    }

    bool operator != (const Bubble& b)
    {
        if(x != b.x || y != b.y || b.r != r || b.outline != outline || b.fill != fill)
        {
            return true;
        }

        return false;
    }

private:
};
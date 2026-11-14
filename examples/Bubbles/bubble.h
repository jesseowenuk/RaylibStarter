#pragma once

class Bubble
{
public:
    int x;
    int y;
    int r;

    // Constructor
    Bubble(int bubble_x, int bubble_y, int bubble_r)
    {
        x = bubble_x;
        y = bubble_y;
        r = bubble_r; 
    }

    void move();
    void show();

private:
};
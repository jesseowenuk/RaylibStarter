#pragma once

class Bubble
{
public:
    int x;
    int y;
    int r;
    bool is_clicked;

    // Constructor
    Bubble(int bubble_x, int bubble_y, int bubble_r);

    void move();
    void show();
    void change_colour();
    bool contains(float temp_x, float temp_y);

private:
};
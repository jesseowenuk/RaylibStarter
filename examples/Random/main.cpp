#include "raylib.h"

float square_size;
float line_width;

void setup()
{
    // Setup code goes here
    const int screen_width = 400;
    const int screen_height = 300;

    InitWindow(screen_width, screen_height, "Raylib Starter Project");
    SetTargetFPS(60);

    ClearBackground({100, 100, 100, 255});
}

void draw()
{
    // This is drawn every frame

    square_size = GetRandomValue(50, 250);
    line_width = GetRandomValue(1, 15);
    
    Rectangle my_square = {200 - square_size / 2, 150 - square_size / 2, square_size, square_size};
    DrawRectangleRec(my_square, {0, 255, 0, 50});
    DrawRectangleLinesEx(my_square, line_width, {0, 0, 255, 50});
}

int main()
{
    setup();

    while(!WindowShouldClose())
    {
        BeginDrawing();

        draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
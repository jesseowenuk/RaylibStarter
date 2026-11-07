#include "raylib.h"

void setup()
{
    // Setup code goes here
}

void draw()
{
    // This is drawn every frame
    ClearBackground(Color({220, 0, 200, 255}));

    DrawLine(0, 50, 400, 300, BLACK);
    DrawRectangle(400 / 2 - 75, 300 / 2 - 75, 150, 150, WHITE);
}

int main()
{
    const int screenWidth = 400;
    const int screenHeight = 300;

    InitWindow(screenWidth, screenHeight, "Raylib Starter Project");
    SetTargetFPS(60);

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
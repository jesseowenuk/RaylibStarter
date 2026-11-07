#include "raylib.h"

void setup()
{
    // Setup code goes here
    const int screenWidth = 400;
    const int screenHeight = 300;

    InitWindow(screenWidth, screenHeight, "Raylib Starter Project");
    SetTargetFPS(60);
}

void draw()
{
    // This is drawn every frame
    ClearBackground(BLACK);

    DrawEllipse(200, 150, 75, 75, WHITE);
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
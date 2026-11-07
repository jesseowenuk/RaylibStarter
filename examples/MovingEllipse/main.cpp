#include "raylib.h"

float circleX = 100;

void setup()
{
    // Setup code goes here
    const int screen_width = 400;
    const int screen_height = 300;

    InitWindow(screen_width, screen_height, "Raylib Starter Project");
    SetTargetFPS(60);
}

void draw()
{
    // This is drawn every frame
    ClearBackground(BLACK);
    
    DrawEllipse(circleX, 150, 15, 15, WHITE);

    circleX++;

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        circleX = 0;
    }
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
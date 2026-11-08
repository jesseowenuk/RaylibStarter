#include "raylib.h"

RenderTexture2D canvas;

int x = 300;
int y = 200;
int x_speed = 3;
int y_speed = 3;

void setup()
{
    // Specify the screen width and height
    const int screen_width = 600;
    const int screen_height = 400;

    // Initialise the window
    InitWindow(screen_width, screen_height, "Raylib Starter Project");
    SetTargetFPS(60);

    // Create a texture to draw to
    canvas = LoadRenderTexture(screen_width, screen_height);
}

void draw()
{
    // This is drawn every frame - put drawing calls here
    ClearBackground(BLACK);

    DrawEllipseLines(x, y, 50, 50, WHITE);

    if(x > GetScreenWidth())
    {
        x_speed = -3;
    }

    if(x < 0)
    {
        x_speed = 3;
    }

    if(y > GetScreenHeight())
    {
        y_speed = -3;
    }

    if(y < 0)
    {
        y_speed = 3;
    }
    x = x + x_speed;
    y = y + y_speed;
}

int main()
{
    setup();

    while(!WindowShouldClose())
    {
        BeginTextureMode(canvas);
        draw();
        EndTextureMode();

        // Draw the frame to the screen
        BeginDrawing();

        DrawTextureRec(
            canvas.texture,
            {0, 0, (float)canvas.texture.width, -(float)canvas.texture.height},
            {0, 0},
            WHITE
        );

        EndDrawing();
    }

    // Clean up after ourselves
    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}
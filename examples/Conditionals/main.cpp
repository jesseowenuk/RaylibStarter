#include "raylib.h"
#include "helper.h"

RenderTexture2D canvas;

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

    if(GetMouseX() > 250)
    {
        DrawEllipseLines(300, 200, 32, 32, WHITE);
    }
    else if(GetMouseX() > 150)
    {
        DrawRectangleLines(300, 200, 100, 100, WHITE);
    }
    else if(GetMouseX() > 50)
    {
        DrawLine(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
    }
    else
    {
        DrawPixel(300, 200, WHITE);
    }
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
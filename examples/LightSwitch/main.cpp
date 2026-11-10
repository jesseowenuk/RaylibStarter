#include "raylib.h"
#include "helper.h"

bool on = false;

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
    if(on)
    {
        ClearBackground(GREEN);
    }
    else
    {
        ClearBackground(BLACK);
    }

    DrawRectangleLines(250, 150, 100, 100, WHITE);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if(GetMouseX() > 250 && GetMouseX() < 350 && GetMouseY() > 150 && GetMouseY() < 250)
        {
            on = !on;
        }
    }

    if(GetMouseX() > 250 && GetMouseX() < 350 && GetMouseY() > 150 && GetMouseY() < 250)
    {
        DrawRectangle(250, 150, 100, 100, PINK);
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
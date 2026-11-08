#include "raylib.h"
#include "helper.h"

RenderTexture2D canvas;

int r = 0;
int b = 255;

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
    r = remap(GetMouseX(), 0, 600, 0, 255);
    b = remap(GetMouseX(), 0, 600, 255, 0);
    ClearBackground({(unsigned char)r, 0, (unsigned char)b, 255});

    DrawEllipse(GetMouseX(), 200, 32, 32, {250, 118, 222, 255});
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
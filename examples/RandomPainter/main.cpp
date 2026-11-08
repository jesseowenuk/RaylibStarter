#include "raylib.h"

RenderTexture2D canvas;

float circle_size = 12;
int r = 255;
int g = 255;
int b = 255;
int a = 255;

void setup()
{
    // Specify the screen width and height
    const int screen_width = 400;
    const int screen_height = 300;

    // Initialise the window
    InitWindow(screen_width, screen_height, "Raylib Starter Project");
    SetTargetFPS(60);

    // Create a texture to draw to
    canvas = LoadRenderTexture(screen_width, screen_height);
    BeginTextureMode(canvas);
    ClearBackground(BLACK);
    EndTextureMode();
}

void draw()
{
    // This is drawn every frame - put drawing calls here

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        circle_size = GetRandomValue(10, 35);
        r = GetRandomValue(0, 255);
        g = GetRandomValue(0, 255);
        b = GetRandomValue(0, 255);
        a = GetRandomValue(0, 255);
    }

    DrawEllipse(GetMouseX(), GetMouseY(), circle_size, circle_size, {(unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a});
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
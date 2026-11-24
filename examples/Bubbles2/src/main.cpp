#include "raylib.h"

#define RAYMATH_IMPLEMENTATION
#include "raymath.h"

#include "bubble.h"

RenderTexture2D canvas;

Bubble bubble1 = Bubble(200, 200);
Bubble bubble2 = Bubble(325, 200, 100);

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

    if(bubble1.intersects(bubble2))
    {
        ClearBackground({200, 0, 100, 255});
    }

    bubble1.show();
    bubble2.show();
    bubble1.move();
    bubble2.move();
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
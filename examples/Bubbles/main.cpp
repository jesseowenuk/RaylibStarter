#include "raylib.h"

#include "bubble.h"

RenderTexture2D canvas;

Bubble my_bubble1(200, 200, 20);
Bubble my_bubble2(400, 200, 10);

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
}

void draw()
{
    // This is drawn every frame - put drawing calls here
    ClearBackground(BLACK);

    my_bubble1.move();
    my_bubble1.show();

    my_bubble2.move();
    my_bubble2.show();
    
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
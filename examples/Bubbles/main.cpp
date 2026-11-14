#include "raylib.h"

#include <vector>

#include "bubble.h"

RenderTexture2D canvas;

std::vector<Bubble> bubbles;

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

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        int r = GetRandomValue(10, 50);
        Bubble b(GetMouseX(), GetMouseY(), r);
        bubbles.emplace_back(b);
    }

    for(Bubble a_bubble : bubbles)
    {
        a_bubble.move();
        a_bubble.show();
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
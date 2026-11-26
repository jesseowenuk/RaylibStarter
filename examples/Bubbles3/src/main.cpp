#include "raylib.h"

#define RAYMATH_IMPLEMENTATION
#include "raymath.h"

#include <vector>

#include "bubble.h"

RenderTexture2D canvas;

std::vector<Bubble> bubbles;
Bubble my_bubble(GetMouseX(), GetMouseY(), 10);

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

    for(int i = 0; i < 1000; i++)
    {
        int x = GetRandomValue(0, GetScreenWidth());
        int y = GetRandomValue(0, GetScreenHeight());
        int r = GetRandomValue(5, 8);
        Bubble b = Bubble(x, y, r);
        bubbles.push_back(b);
    }
}

void draw()
{
    // This is drawn every frame - put drawing calls here
    ClearBackground(BLACK);

    for(int i = 0; i < bubbles.size(); i++)
    {
        bubbles[i].show();
        bubbles[i].move();
        bool overlapping = false;

        for(int j = 0; j < bubbles.size(); j++)
        {
            if(bubbles[i] != bubbles[j] && bubbles[i].intersects(bubbles[j]))
            {
                overlapping = true;
            }
        }

        if(overlapping)
        {
            bubbles[i].change_colour(255, 255);
        }
        else
        {
            bubbles[i].change_colour(255, 0);
        }
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
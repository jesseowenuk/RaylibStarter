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

    for(int i = 0; i < 10; i++)
    {
        int x = GetRandomValue(0, GetScreenWidth());
        int y = GetRandomValue(0, GetScreenHeight());
        int r = GetRandomValue(5, 25);

        Bubble b(x, y, r);
        bubbles.emplace_back(b);
    }
}

void draw()
{
    // This is drawn every frame - put drawing calls here
    ClearBackground(BLACK);

    for(int i = 0; i < bubbles.size(); i++)
    {
        if(bubbles[i].contains(GetMouseX(), GetMouseY()))
        {
            bubbles[i].change_colour();
        }
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        for(int i = bubbles.size() - 1; i >= 0; i--)
        {
            if(bubbles[i].contains((float)GetMouseX(), (float)GetMouseY()))
            {
                bubbles.erase(bubbles.begin() + i);
            }
        }
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
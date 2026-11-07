#include "raylib.h"

float x;
float y;
float z;
int r;
int g;
int b;

RenderTexture2D canvas;

void setup()
{
    // Setup code goes here
    const int screen_width = 1024;
    const int screen_height = 569;

    InitWindow(screen_width, screen_height, "Raylib Starter Project");
    SetTargetFPS(60);

    canvas = LoadRenderTexture(screen_width, screen_height);

    BeginTextureMode(canvas);
    ClearBackground(BLACK);
    EndTextureMode();
}

void draw()
{
    // This is drawn every frame

    r = GetRandomValue(0, 255);
    g = 0;
    b = GetRandomValue(0, 255);
    x = GetRandomValue(0, GetScreenWidth());
    y = GetRandomValue(0, GetScreenHeight());

    DrawEllipse(x, y, 12, 12, {(unsigned char)r,(unsigned char)g, (unsigned char)b, 100});
}

int main()
{
    setup();

    while(!WindowShouldClose())
    {
        BeginTextureMode(canvas);
        draw();
        EndTextureMode();

        BeginDrawing();

        DrawTextureRec(
            canvas.texture,
            {0, 0, (float)canvas.texture.width, -(float)canvas.texture.height},
            {0, 0},
            WHITE
        );

        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}
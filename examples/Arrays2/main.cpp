#include "raylib.h"

#include <string>

RenderTexture2D canvas;

std::string words[5] = {"rainbow", "heart", "purple", "friendship", "love"};
int word_index = 0;

void setup()
{
    // Specify the screen width and height
    const int screen_width = 400;
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

    DrawText(TextFormat("%s", words[word_index].c_str()), 12, 200, 32, WHITE);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        word_index = word_index + 1;
    }

    if(word_index == sizeof(words) / sizeof(words[0]))
    {
        word_index = 0;
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
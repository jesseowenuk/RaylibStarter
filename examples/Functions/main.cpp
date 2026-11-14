#include "raylib.h"

RenderTexture2D canvas;

struct ball
{
    int x;
    int y;
    int x_speed;
    int y_speed;
};

ball my_ball = {300, 200, 4, -3};

void move()
{
    my_ball.x = my_ball.x + my_ball.x_speed;
    my_ball.y = my_ball.y + my_ball.y_speed;
}

void bounce()
{
    if(my_ball.x > GetScreenWidth() || my_ball.x < 0)
    {
        my_ball.x_speed = my_ball.x_speed * -1;
    }

    if(my_ball.y > GetScreenHeight() || my_ball.y < 0)
    {
        my_ball.y_speed = my_ball.y_speed * -1;
    }
}

void display()
{
    DrawEllipseLines(my_ball.x, my_ball.y, 12, 12, WHITE);
}

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

    move();
    bounce();
    display();
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
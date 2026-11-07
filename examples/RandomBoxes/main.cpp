// Random Boxes
// Click to generate a new random box picture

#include "raylib.h"

float house_height;
float house_width;
float door_height;
float door_width;
float window_size;

void setup()
{
    // Setup code goes here
    const int screen_width = 400;
    const int screen_height = 300;

    InitWindow(screen_width, screen_height, "Raylib Starter Project");
    SetTargetFPS(60);
}

void draw()
{
    // This is drawn every frame
    ClearBackground(SKYBLUE);
    
    // Draw the ground and grass
    Rectangle ground = {0, 200, 400, 100};
    Rectangle grass = {0, 200, 400, 10};

    DrawRectangleRec(ground, BROWN);
    DrawRectangleRec(grass, GREEN);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        house_height = GetRandomValue(50, 150);
        house_width = GetRandomValue(100, 350);
        door_height = GetRandomValue(50, house_height / 2);
        door_width = GetRandomValue(50, 100);
        window_size = GetRandomValue(10, 50);
    }

    // Draw house square
    DrawRectangle(200 - house_width / 2, 200 - house_height, house_width, house_height, RED);

    // Draw two windows
    DrawRectangle(200 - (house_width / 2) - (house_width / 4), 200 - house_height - 10, window_size, window_size, BLUE);
    DrawRectangle(200 - (house_width / 2) + (house_width / 4), 200 - house_height - 10, window_size, window_size, BLUE);

    // Draw the door
    DrawRectangle(200 - door_width / 2, 200 - door_height, door_width, door_height, BLACK);
}

int main()
{
    setup();

    while(!WindowShouldClose())
    {
        BeginDrawing();

        draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
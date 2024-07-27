#include<bits/stdc++.h>
#include "raylib.h"

using namespace std;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib Window");

    SetTargetFPS(10);
    int i = 0;
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        i++;

        DrawCircle(i,i,20,WHITE);

        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}

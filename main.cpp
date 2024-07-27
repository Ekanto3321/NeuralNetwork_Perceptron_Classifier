#include<bits/stdc++.h>
#include "raylib.h"

using namespace std;

void draw(int height, int width);

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib Window");

    draw(screenHeight,screenWidth);
    
    return 0;
}


void draw(int height, int width){
    
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

}
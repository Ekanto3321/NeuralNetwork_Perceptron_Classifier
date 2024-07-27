#include<bits/stdc++.h>
#include "raylib.h"
#include "perc.cpp"

using namespace std;

void draw(int height, int width);

int main()
{   
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib Window");

    perceptron perc;

    for (int i = 0; i < perc.weights.size(); i++)
    {   
        cout<<perc.weights[i]<<endl;
    }
    

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
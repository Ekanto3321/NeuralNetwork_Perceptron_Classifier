#include<bits/stdc++.h>
#include "raylib.h"
#include "perc.cpp"

void draw(int height, int width, int i);

using namespace std;
const int screenWidth = 600;
const int screenHeight = 600;


int main()
{   

    InitWindow(screenWidth, screenHeight, "Raylib Window");

    perceptron perc;

    vector<float> input = {1,-0.5};

    cout<<"****output: "<<perc.think(input)<< endl;
    
    SetTargetFPS(10);
    int i = 0;
    
    // draw(screenHeight,screenWidth, i);

    CloseWindow(); 
    
    return 0;
}


void draw(int height, int width, int i){
    
    
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        i++;

        DrawCircle(i,i,20,WHITE);

        EndDrawing();
    }


}
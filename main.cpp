#include<bits/stdc++.h>
#include "raylib.h"
#include "perc.cpp"
#include "point.cpp"

void drawWindow(int height, int width, vector<point> &pt);
void drawPt(vector<point> &pt);

void init();

using namespace std;
const int screenWidth = 600;
const int screenHeight = 600;
int numPoints = 50;

int main()
{   
    init();

    perceptron perc;

    vector<point> pt;
    for (int i = 0; i < numPoints; i++)
    {   
        point newpt(screenHeight,screenWidth);
        pt.push_back(newpt);
    }
    

    vector<float> input = {1,-0.5};

    cout<<"****output: "<<perc.think(input)<< endl;
    
    SetTargetFPS(10);
    int i = 0;
    
    drawWindow(screenHeight,screenWidth, pt);

    CloseWindow(); 
    
    return 0;
}


void drawWindow(int height, int width, vector<point> &pt){
    
    ClearBackground(BLACK);
    
    while (!WindowShouldClose()) 
    {
        BeginDrawing();

        drawPt(pt);

        EndDrawing();
    }


}

void drawPt(vector<point> &pt){

    for (int i = 0; i < pt.size(); i++)
    {
        if(pt[i].label==1){
            DrawCircle(pt[i].x,pt[i].y,10,WHITE);
            DrawCircle(pt[i].x,pt[i].y,8,BLACK);
        } else {
            DrawCircle(pt[i].x,pt[i].y,10,WHITE);
        }
    }
    
}

void init(){
    InitWindow(screenWidth, screenHeight, "Perceptron classification");

}
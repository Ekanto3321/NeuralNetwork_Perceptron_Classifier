#include<iostream>
#include<vector>
#include "raylib.h"
#include "perc.cpp"
#include "point.cpp"


void drawWindow(int height, int width, vector<point> &pt);
void drawPt(vector<point> &pt);

void init();

using namespace std;

perceptron perc; //initializing the perceptron only once
const int screenWidth = 600;
const int screenHeight = 600;
int numPoints = 100;

int main() {
    perceptron p;

    vector<float> input = {1.0, -1.0};  // Example inputs
    int target = 1;  // Example target output

    //print initial weights
    vector<float> weights1 = p.getWeights();
    cout << "Updated weights:" << endl;
    for (float weight : weights1) {
        cout << weight << " ";
    }
    cout << endl;

    // Train the perceptron
    p.train(input, target);

    // Print updated weights
    vector<float> weights2 = p.getWeights();
    cout << "Updated weights:" << endl;
    for (float weight : weights2) {
        cout << weight << " ";
    }
    cout << endl;

    return 0;
}


// int main()
// {   
//     init();

//     SetTargetFPS(1);

//     vector<point> pt;

//     for (int i = 0; i < numPoints; i++)
//     {   
//         point newpt(screenHeight,screenWidth);
//         pt.push_back(newpt);
//     }
    

//     vector<float> input = {100,150};

//     // cout<<"****output: "<<perc.think(input)<< endl;
    
    
//     drawWindow(screenHeight,screenWidth, pt);

//     CloseWindow(); 
    
//     return 0;
// }


void drawWindow(int height, int width, vector<point> &pt){
    
    ClearBackground(BLACK);
    int i = 0;
    while (!WindowShouldClose()) 
    {   
        BeginDrawing();
            
            DrawLine(0,0,screenHeight,screenWidth,LIGHTGRAY);
            drawPt(pt);
            cout<<++i<<endl;
            
        EndDrawing();
    }


}

void drawPt(vector<point> &pt){

    for (int i = 0; i < pt.size(); i++)
    {
        // if(pt[i].label==1){
        //     DrawCircle(pt[i].x,pt[i].y,8,WHITE);
        //     DrawCircle(pt[i].x,pt[i].y,6,BLACK);
        // } else {
        //     DrawCircle(pt[i].x,pt[i].y,8,WHITE);
        // }

        vector<float> inputs = {pt[i].x,pt[i].y};
        int target = pt[i].label;

        cout<<perc.getWeights()[0]<<" "<<perc.getWeights()[1]<<endl;

        perc.train(inputs,target);

        cout<<perc.getWeights()[0]<<" "<<perc.getWeights()[1]<<endl;

        int eduGuess = perc.think(inputs); 

        if(eduGuess == target){
            DrawCircle(pt[i].x, pt[i].y,4,GREEN);
        } else {
            DrawCircle(pt[i].x, pt[i].y,4,RED);
        }
        
        cout << endl;
    }

    
}

void init(){
    InitWindow(screenWidth, screenHeight, "Perceptron classification");

}
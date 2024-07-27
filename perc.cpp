#include<bits/stdc++.h>
#include <random>
#include <ctime>


using namespace std;

class perceptron{

public:
    vector<float> inputs;
    vector<float> weights;

    perceptron(){

        inputs.resize(2);
        weights.resize(2);

        for (int i = 0; i < weights.size(); i++){
            weights[i] = rnd(-1,1); 
            cout<<"weights: "<<weights[i]<<endl;
        }
            
    }

    int think(vector<float> &inputs){

        float sum = 0;
        for (int i = 0; i < inputs.size(); i++)
        {
            sum += inputs[i]*weights[i];
        }
        return act(sum);

    }

    int act(float x){
        if(x>=0){
            return 1;
        } else {
            return -1;
        }
    }

    float rnd(float min, float max) {

        srand(time(NULL)+rand());
	    return ((float)rand() / RAND_MAX) * (max - min) + min;

    }



};
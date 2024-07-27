#include<vector>
#include <random>
#include <ctime>
#include<iostream>


using namespace std;

class perceptron{

public:
    vector<float> inputs;
    vector<float> weights;
    float learningRate = 0.04;
    float totalError = 0;

    perceptron(){

        inputs.resize(2);
        weights.resize(2);

        for (int i = 0; i < weights.size(); i++){
            weights[i] = rnd(-1,1); 
        }
            
    }

    int think(vector<float> &inputs){

        float sum = 0;
        for (int i = 0; i < inputs.size(); i++){
            sum += inputs[i]*weights[i];
        }
        cout<<"sum: "<<sum<<endl;
        return act(sum);

    }

    void train(vector<float> &input, int target){
        int guess = think(input);
        int error = target - guess;
        for (int i = 0; i < weights.size(); i++){
            weights[i] = weights[i] + (error*input[i]*learningRate);
        }

    }

    vector<float> getWeights(){
        return weights;
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
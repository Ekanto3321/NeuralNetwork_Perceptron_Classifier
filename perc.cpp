#include<bits/stdc++.h>

using namespace std;

class perceptron{

public:
    vector<float> inputs;
    vector<float> weights;

    perceptron(){
        inputs.resize(3);
        weights.resize(3);

        for (int i = 0; i < weights.size(); i++)weights[i] = 1; 
            
    }

    void think(){

        

    }


};
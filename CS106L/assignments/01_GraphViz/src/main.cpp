/*
 * TODO: complete this file comment.
 */
#include <iostream>
#include <fstream>
#include<sstream>
#include "SimpleGraph.h"
#include <cmath> // for sin and cos
#include<utility>
#include<chrono>
#include<algorithm>
using namespace std;

bool flag = 1;
void Welcome();
int input_microseconds(){
    while(1){
        string string_seconds;
        cin>>string_seconds;
        istringstream iss(string_seconds);
        int microseconds;
        char remain;
        if(!(iss>>microseconds) || (iss>>remain)){
            cout<<"Input valid, retry.."<<endl;
        }
        else return microseconds;
    }
}

void input_prompt(){
    cout<<"Do you want to open a new file? Input yes or no"<<endl;
    while(1){
        string prompt;
        cin>>prompt;
        if(prompt == "yes"){
            return;
        }
        else if(prompt == "no"){
            flag = false;
            return;
        }
        else{
            cout<<"Input valid, retry..."<<endl;
        }
    }
}
// Main method
int main() {
    Welcome();
    /* TODO: your implementation here */

    while(flag){
        struct SimpleGraph mygraph;
        InitGraphVisualizer(mygraph);
        ifstream myfilestream;
        while(!myfilestream.is_open()){
            string filename;
            cout<<"Please input the file name"<<endl;
            cin>>filename;
            myfilestream.open(filename);
        }
        cout<<"File is opened sucessfully"<<endl;

        //initilize the graph
        int node_num;
        myfilestream>>node_num;
        const double kPi = 3.14159265358979323;
        for(int i = 0 ; i < node_num; i++){
            double x, y;
            x = cos(2*kPi*i/node_num);
            y = sin(2*kPi*i/node_num);
            mygraph.nodes.push_back({x, y});
        }
        size_t one, two;
        string line;
        //while(myfilestream>>one>>two){
        //           mygraph.edges.push_back({one,two});
        //       }
        while(getline(myfilestream, line)){
            stringstream s(line);
            //cout<<"this is a line:"<<line<<endl;
            //确保输入数据有效，因为最开始会读入空行
            if(s>>one>>two) mygraph.edges.push_back({one, two});
        }
        DrawGraph(mygraph);

        cout<<"Please input the limit microseconds"<<endl;
        int upper_microseconds = input_microseconds();
        int milliseconds = 0;
        cout<<"upper_mircroseconds is "<<upper_microseconds<<"ms."<<endl;

        //start compute
        cout<<"start computing...."<<endl;
        auto start = chrono::high_resolution_clock::now();
        while( milliseconds <= upper_microseconds){
            // double delta_x0, delta_y0, delta_x1, delta_y1;
            //compute the attractive force
            const double kattract = 0.001;
            for(auto edge : mygraph.edges){
                pair<double, double> node1, node2;
                node1 = make_pair(mygraph.nodes[edge.start].x,mygraph.nodes[edge.start].y);
                node2 = make_pair(mygraph.nodes[edge.end].x,mygraph.nodes[edge.end].y);
                auto Fattract = kattract * ((node2.first - node1.first)*(node2.first - node1.first) +
                                     (node2.second - node1.second)*(node2.second - node1.second));
                auto theta = atan2(node2.second - node1.second, node2.first - node1.first);
                mygraph.nodes[edge.start].x += Fattract * cos(theta);
                mygraph.nodes[edge.start].y += Fattract * sin(theta);
                mygraph.nodes[edge.end].x -= Fattract * cos(theta);
                mygraph.nodes[edge.end].y -= Fattract * sin(theta);
            }
            //compute the repel force
            const double krepel = 0.001;
            for(int i = 0; i < static_cast<int>(mygraph.nodes.size()); i++){
                for(int j = i + 1; j < static_cast<int>(mygraph.nodes.size()); j++){
                    if(i != j){
                        pair<double, double> node1, node2;
                        node1 = make_pair(mygraph.nodes[i].x,mygraph.nodes[i].y);
                        node2 = make_pair(mygraph.nodes[j].x,mygraph.nodes[j].y);
                        auto Frepel = krepel / sqrt((node2.first - node1.first)*(node2.first - node1.first) +
                                                    (node2.second - node1.second)*(node2.second - node1.second));
                        auto theta = atan2(node2.second - node1.second, node2.first - node1.first);
                        mygraph.nodes[i].x -= Frepel * cos(theta);
                        mygraph.nodes[i].y -= Frepel * sin(theta);
                        mygraph.nodes[j].x += Frepel * cos(theta);
                        mygraph.nodes[j].y += Frepel * sin(theta);
                    }
                }
            }
            DrawGraph(mygraph);
            auto end = chrono::high_resolution_clock::now();
            //convert to milliseconds
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
            milliseconds = elapsed.count();
        }
        cout<<"Iteration end, do you want to continue?"<<endl;
        input_prompt();

    }

    return 0;
}


/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}



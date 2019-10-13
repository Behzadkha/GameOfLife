/**
 * \file Display.cpp
 * \author Behzad Khamneli, mcid: khamnelb
 * \brief Creates an output file and display the grid.
 */
#include "Display.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#define size 15

void Show::output(string** pointer){
  ofstream outfile("./output.txt");
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(pointer[i][j] == "yes"){
        outfile << i << ",";
        outfile << j << "\n";
      }
    }
  }
  outfile.close();
}

void Show::printer(string** pointer1){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(pointer1[i][j] == "yes"){
        cout << " 0 ";
      }
      else{
        cout << " . ";
      }
      if(j == size - 1){
        cout << endl;
      }
    }
  }
  cout << "\n";
}

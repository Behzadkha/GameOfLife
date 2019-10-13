//collaborator : Behdad Khamneli
//resource : https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/
/**
 * \file GameBoard.cpp
 * \author Behzad Khamneli, mcid: khamnelb
 * \brief Creates the game.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "GameBoard.h"
#include <stdexcept>
using namespace std;
#define size 15

Game::Game(string fileName){
  ifstream readfile;
  readfile.open(fileName);
  if(readfile.is_open()){
    string line;
    string x,y;
    char delim = ',';
    while(getline(readfile,line)){
      stringstream ss(line);
      getline(ss,x,delim);
      getline(ss,y,delim);
      if(stoi(x) < 0 || stoi(y) < 0 || stoi(x) >= 15 || stoi(y) >= 15){
        throw out_of_range("Points should be between 0-14(Grid size is 15x15)");
      }
      else{
        this->coordinates[stoi(x)][stoi(y)] = "yes";
      } 
    }
  }
  else{
    throw invalid_argument ("File cannot be found");
  }
}
void Game::status(){
  string copy[size][size] = {};
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      copy[i][j] = coordinates[i][j];
    }
  }
  for(int m = 0; m < size; m++){
    for(int n = 0; n < size; n++){
      int checker = 0;
      for(int r = -1; r < 2; r++){
        for(int c = -1; c < 2; c++){
          if((m+r >= 0 && m+r < 15) && (n+c >= 0 && n+c < 15) && !(r==0 && c==0)){
            if(copy[m+r][n+c] == "yes"){
              checker++;
            }
          }
        }
      }
      if(checker < 2){
        coordinates[m][n] = "dead";
      }
      if(checker == 3){
        coordinates[m][n] = "yes";
      }
      else if(checker > 3){
        coordinates[m][n] = "dead";
      }
    }
  }
}
string** Game::getCoordinates(){
  string ** newCoordinates = new string *[size];
  for (int i = 0; i < size; i++){
    newCoordinates[i] = new string[size];
  }
  for(int r = 0; r < size; r++){
    for(int c = 0; c < size; c++){
      newCoordinates[r][c] = coordinates[r][c];
    }
  }
  return newCoordinates;  
}
void Game::setAlive(int x,int y){
  if(x < 0 || x >= 15 || y < 0 || y >= 15){
    throw out_of_range("points should be between 0-14(grid size is 15x15)");
  }
  else{
    coordinates[x][y] = "yes";
  }
}
void Game::setDead(int x, int y){
  if(x < 0 || x >= 15 || y < 0 || y >= 15){
    throw out_of_range("points should be between 0-14(grid size is 15x15)");
  }
  else{
    coordinates[x][y] = "dead";
  }
} 

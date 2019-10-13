#include <iostream>
#include "GameBoard.h"
#include "Display.h"
#define size 15
int main(){
  Game GameBoard("input.txt");
  Show Dis;
  int i = 0;
  while(i < 5){
    Dis.output(GameBoard.getCoordinates());
    Dis.printer(GameBoard.getCoordinates());
    GameBoard.status();
    i++;
  }/*
  Game GameBoard("input.txt");
  GameBoard.status();
  Show mydis;
  string** get = GameBoard.getCocrdinates(); 
  mydis.easy(get);*/
}

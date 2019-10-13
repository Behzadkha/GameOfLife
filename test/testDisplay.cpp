#include <iostream>
#include "GameBoard.h"
#include "Display.h"
#include "catch.h"
#include <fstream>
#include <sstream>

TEST_CASE("test for Display", "[Show]"){
  ofstream outfile("input.txt");
  outfile << "2,9" << "\n";
  outfile << "2,10" << "\n";
  outfile << "2,11" << "\n";
  outfile.close();
  Game GameBoard("input.txt");
  Show DISP;

  SECTION("general test case for output"){
    GameBoard.status();//1,10 - 2,10 - 3,10 will be alive
    DISP.output(GameBoard.getCoordinates());
    ifstream readfile;
    readfile.open("output.txt");
    string line,x,y;
    char delim = ',';
    int rows[15] = {};
    int col[15] = {};
    int i = 0;
    while(getline(readfile,line) && i < 15){
      stringstream ss(line);
      getline(ss,x,delim);
      getline(ss,y,delim);
      rows[i] = stoi(x);
      col[i] = stoi(y);
      i++;
    }
    REQUIRE(rows[0] == 1);
    REQUIRE(col[0] == 10);
 
    REQUIRE(rows[1] == 2);
    REQUIRE(col[1] == 10);

    REQUIRE(rows[2] == 3);
    REQUIRE(col[2] == 10);
   } 
}

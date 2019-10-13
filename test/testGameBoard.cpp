#include "GameBoard.h"
#include "Display.h"
#include "catch.h"
#include <iostream>
#include <fstream>
using namespace std;

TEST_CASE("test for gameboard", "[Game]"){
  ofstream outfile("input.txt");
  outfile << "2,9" << "\n";
  outfile << "2,10" << "\n";
  outfile << "2,11" << "\n";
  outfile.close();
  Game GameBoard("input.txt");
  Show DISP;

  SECTION("constructor exception test case"){
    ofstream outfile("input.txt");
    outfile << "-2,5" << "\n";
    outfile << "15,15" << "\n";//grid size 15x15 but index for array cannot be 15
    outfile << "-2,72" << "\n";
    outfile.close();
    REQUIRE_THROWS_AS(Game("input.txt"), :: out_of_range);
  }
  SECTION("test case the input file does not exist"){
    REQUIRE_THROWS_AS(Game("INPUT.txt"), :: invalid_argument);
  }
  SECTION("general test case for rows and columns"){
    GameBoard.status();
    string** check = GameBoard.getCoordinates();
    REQUIRE(check[2][10] == "yes");
    REQUIRE(check[2][1] == "dead");
  }
  SECTION("boundary test cases for Game"){
    ofstream outfile("input.txt");
    outfile << "0,0" << "\n";
    outfile << "14,14" << "\n";
    outfile.close();
    Game second("input.txt");
    string** check = second.getCoordinates();
    REQUIRE(check[0][0] == "yes");
    REQUIRE(check[14][14] == "yes");
  }
  SECTION("general test cases for status"){
    GameBoard.status();
    string** check = GameBoard.getCoordinates();
    REQUIRE(check[2][9] == "dead");//based on the rules it dies after first step
    REQUIRE(check[2][11] == "dead"); 
    REQUIRE(check[1][10] == "yes");//after the first step, point 1,10 will be alive
    REQUIRE(check[3][10] == "yes");
  }
  SECTION("boundary test cases for status"){
    ofstream outfile("input.txt");
    outfile << "0,0" << "\n";//point near the edge
    outfile << "0,1" << "\n";
    outfile << "0,2" << "\n";
    outfile.close();
    Game second("input.txt");
    second.status();
    string** check = second.getCoordinates();
    REQUIRE(check[0][0] == "dead");
    REQUIRE(check[0][1] == "yes");
  }
  SECTION("general test cases for setAlive"){
    GameBoard.setAlive(2,4);
    string** check = GameBoard.getCoordinates();
    REQUIRE(check[2][4] == "yes");
  }
  SECTION("exception test case for setAlive"){
    REQUIRE_THROWS_AS(GameBoard.setAlive(16,-1), :: out_of_range);
  }
  SECTION("boundary test case for setALive"){
    GameBoard.setAlive(0,0);
    GameBoard.setAlive(14,14);
    string** check = GameBoard.getCoordinates();
    REQUIRE(check[0][0] == "yes");
    REQUIRE(check[14][14] == "yes");
  } 
  SECTION("general test case for setDead"){
    GameBoard.setDead(2,4);
    string** check = GameBoard.getCoordinates();
    REQUIRE(check[2][4] == "dead");
  }
  SECTION("exception test case for setDead"){
    REQUIRE_THROWS_AS(GameBoard.setDead(16,-1), :: out_of_range);
  }
  SECTION("boundary test case for setDead"){
    GameBoard.setDead(0,0);
    GameBoard.setDead(14,14);
    string** check = GameBoard.getCoordinates();
    REQUIRE(check[0][0] == "dead");
    REQUIRE(check[14][14] == "dead");
  }
}

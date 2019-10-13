//collaborator: Behdad Khamneli
//resource: https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/
/**
 * \file GameBoard.h
 * \author Behzad Khamneli, mcid: khamnelb
 * \brief Creates the game.
 */
#ifndef A4_Game_Board_H_
#define A4_Game_Board_H_
#include <string>

using namespace std;
class Game{
  private:
    /**
     * \brief A string array for 15x15 grid
     */
    string coordinates[15][15];
  public:
    /**
     * \brief Constructor that takes a file name as an input
     * \details It reads the input file and sets the given points to yes
     */
    Game(string fileName);

    /**
     * \brief Applys the rules of the game
     * \details It checks the points around a live point.
     */
    void status();

    /**
     * \brief Gets the points
     * \return A pointer to a pointer to a string(double pointer)
     */
    string** getCoordinates();

    /**
     * \brief It sets a point to yes(makes them alive)
     * \param x Is an integer that represents rows
     * \param y Is an integer that represents columns
     */
    void setAlive(int x, int y);

    /**
     * \brief It set a point to dead
     * \param x Is an integer that represents rows
     * \param y Is an integer that reoresents columns
     */
    void setDead(int x, int y);	
};
#endif

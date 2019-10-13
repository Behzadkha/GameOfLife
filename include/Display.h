//collaborator : Behdad Khamneli
/**
 * \file Display.h
 * \author Behzad Khamneli, mcid : khamnelb
 * \brief Creates an output file and displays the grid to user.
 */
#ifndef A4_DISPLAY_H_
#define A4_DISPLAY_H_
#include <iostream>
using namespace std;
class Show{
  public:
    /**
     * \brief Creates an output file
     * \param pointer is a double pointer to the array that has the points.
     */
    void output(string** pointer);

    /**
     * \brief Displays the grid 
     * \param pointer1 is a double pointer to the array that has the points.
     * \details If a point is alive it prints '0' otherwise '.'.
     */
    void printer(string** pointer1);
};
#endif

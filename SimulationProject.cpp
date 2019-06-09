/*
 * @file SimulationProject.cpp
 * @author Tyler Barnard
 * @date November 23, 2018
 * This program uses a Priority Queue to store
 * items of the Passenger class type. It reads data from a file
 * and creates Passenger objects which are stored in the queues.
 * Then 2 different sorting algorithms are used to order them based on
 * Airworthy's boarding procedures, and the sorted results are ouput
 * along with an estimate of how long each procedure would take.
 */
#include "Airworthy.h"
#include <cstdlib>
#include <iostream>
using namespace std; 

void description();
   
int main (void)
{  
   
   
   //display a description of the program
   description();
   
   //create Airworthy class for simulation
   Airworthy boardSim;
   
   for (int i = 1; i < 4; i++)
   {
      //create the priority queues
      cout << "Opening file " << i << "." << endl;
      boardSim.createQueuesAll(i);
      cout << "Closing file " << i << "." << endl;
      
      //run the simulations
      cout << "Running simulation  " << i << "..." << endl;
      boardSim.runSimAll(i);
      cout << "Saving data simulation data." << endl << endl;
   }
   
   cout << "Closing program.";
    return EXIT_SUCCESS;
}

//prints a description of the program
void description()
{
   cout << "This program simulates 2 different boarding procedures for Airworthy Airlines, to determine the most efficiant method. " << endl;
   cout << "The first procedure is to organize passengers by row, and let them on from front to back. " << endl;
   cout << "The second procedure it to forgo any sorting and allow passengers to board however they line up." << endl;
   cout << "Both methods do allow for priority passengers to be seated before general boarding." << endl << endl << endl;
}

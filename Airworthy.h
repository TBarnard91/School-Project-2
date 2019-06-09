/**
 * @file Airworthy.h
 * @author Tyler Barnard
 * @date  November 23, 2018
 * @class FilmDatabase
 * This class uses a Priority Queue to store
 * items of the Passenger class type. It reads data from a file
 * and creates Passenger objects which are stored in the queues.
 * Then 2 different sorting algorithms are used to order them based on
 * Airworthy's boarding procedures, and the sorted results are ouput
 * along with an estimate of how long each procedure would take.
 */
#ifndef AIRWORTHY_H
#include "Heap_PriorityQueue.h"
#include "Passenger.h"
using namespace std;


class Airworthy
{
   
private:

   
public:
   /**
    * binary search tree to store Film data
    */
   
   static Heap_PriorityQueue<Passenger> oldQueue;
   static Heap_PriorityQueue<Passenger> newQueue;
   
   static int times;          
   
   // Default Constructor 
   Airworthy();
   
   /*
   * Creates 6 priority queues using passengers from 3 files
   */
   void createQueuesAll(int& f);
   
   /*
   * Simulates the 2 different boarding procedures for 3 pairs of queues, saving
   * the results, boarding order, and time to an ouput file
   */
   void runSimAll(int& f);
   
};

#define AIRWORTHY_H
#endif

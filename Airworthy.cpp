/**
 * @file Airworthy.cpp
 * @author Tyler Barnard
 * @date  November 23, 2018
 * Implementation of the Airworthy class
 * This class uses a Priority Queue to store
 * items of the Passenger class type. It reads data from a file
 * and creates Passenger objects which are stored in the queues.
 * Then 2 different sorting algorithms are used to order them based on
 * Airworthy's boarding procedures, and the sorted results are ouput
 * along with an estimate of how long each procedure would take.
 */
#include "Airworthy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

   //define and initialize static variables 
    Heap_PriorityQueue<Passenger> Airworthy::oldQueue;
    Heap_PriorityQueue<Passenger> Airworthy::newQueue;
      
    Heap_PriorityQueue<Passenger> oldQueue = Airworthy::oldQueue;
    Heap_PriorityQueue<Passenger> newQueue = Airworthy::newQueue;
    
    
    int Airworthy::times = 0;      
    int oldTime = Airworthy::times = 0;      


   // Constructor 
   Airworthy::Airworthy()
   {
   
   }   
   
   /*
   * Creates 6 priority queues using passengers from 3 files
   */
   void Airworthy::createQueuesAll(int& f)
   {
      //variables to hold the values from file, that will be used to create a Passenger object
      int tempKey;
      string tempName;
      char tempType;
      int tempRow;
      
      int oldPriority = 0; //priority using old boarding precedure
      int newPriority = 0; //priority using new boarding procedure
      
      string line;   //variable to hold one line from file
      
      //name of input file
      
      ifstream inFile("airWorthy70.txt");
      
      if (f == 1)
      {
         Passenger::outFile70 << "Original List in the file:" << endl << endl;
      }
      else if (f == 2)
      {
         inFile.close();
         inFile.open("airWorthy85.txt");
         Passenger::outFile85 << "Original List in the file:" << endl << endl;
      }
      else if (f == 3)
      {
         inFile.close();
         inFile.open("airWorthy100.txt");
         Passenger::outFile100 << "Original List in the file:" << endl << endl;
      }
      else
      {
         cout << "Error: invalid file choice";
      }
      
      //count lines in file and add them to output file
      while (getline(inFile, line))
      {
         if (f == 1)
         {
            Passenger::outFile70 << "    " << line << endl;
            
            oldPriority++;
            newPriority++;
         }
         else if (f == 2)
         {
            Passenger::outFile85 << "    " << line << endl;
            
            oldPriority++;
            newPriority++;
         }
         else if (f == 3)
         {
            Passenger::outFile100 << "    " << line << endl;
            
            oldPriority++;
            newPriority++;
         }
         else
         {
            cout << "Error: invalid file choice";
         }    
      }//end while
               
      inFile.clear();             //clear the buffer
      inFile.seekg(0, ios::beg);  //reset the reading position to beginning
      
      
      if(!inFile)
      {
         cout << "Error opening file for input. ";
      }
    ///////////////////////////////////////////////////////////////////////////////  
      for (int i = 1; i < 4; i++)
      {
         //sort out the pre-boarding passengers and add them to the priorityQueue
         while (getline(inFile, line))
         {
            istringstream iss1 (line); //stringstream to parse input
            string token;               //variable to hold one word
            int count = 1; //count to determine current data for each line
            
            while(getline(iss1, token, ' '))
            {
               
               //assign token to approriate variable
               switch (count)
               {
                  case 1:  //name string
                     tempName = token;
                     break;
                  case 2:  //type char
                     tempType = token[0];
                     break;
                  case 3:  //row int
                     tempRow = stoi(token);
                     break;
   
               }//end switch
               
               count++;
            }//end inner while
            
            //check if passenger belongs in priority boarding
            if (tempRow == 10 || tempRow == 11 || tempRow < 5 || tempType == 'H' || tempType == 'E')
            {
               switch (i)
               {
                  case 1:
                  {
                     if (tempType == 'H') //First add passengers who need help boarding
                     {
                        tempKey = newPriority;
              
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                            
                        Airworthy::oldQueue.add(newPassenger);
                        Airworthy::newQueue.add(newPassenger);
                        oldPriority--;
                        newPriority--;
                     }
                     break;
                  }//end case1
                  case 2:
                  {
                     if (tempRow < 5 && tempType != 'H') //Next add passengers who are in first class
                     {
                        tempKey = newPriority;
              
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                            
                        Airworthy::oldQueue.add(newPassenger);
                        Airworthy::newQueue.add(newPassenger);
                        oldPriority--;
                        newPriority--;
                     }
                     break;
                  }//end case2
                  case 3:
                  {
                     if ((tempRow > 4 && tempType != 'H') && (tempRow == 10 || tempRow == 11 || tempType == 'E')) //Then add passengers in exit rows, or who are frequent flyers
                     {
                        tempKey = newPriority;
                        
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                       
                        Airworthy::oldQueue.add(newPassenger);
                        Airworthy::newQueue.add(newPassenger);
                        oldPriority--;
                        newPriority--;
                     }
                     break;
                  }//end case3
               }//end switch 
            }//end if
            
            iss1 >> token;
         }//end outer while
         
         
         
         inFile.clear();             //clear the buffer
         inFile.seekg(0, ios::beg);  //reset the reading position to beginning
         
      }//end for
      
      //////////////////////////////////////////////////////////////////////////////////////////////
      //sort the general boarders by row, and add them to the oldQueue (uses old boarding procedure)
      for (int i = 1; i < 5; i++)
      { 
         inFile.clear();             //clear the buffer
         inFile.seekg(0, ios::beg);  //reset the reading position to beginning
       
         while (getline(inFile, line))//(inFile)
         {
            istringstream iss1 (line); //stringstream to parse input
            string token;               //variable to hold one word
            int count = 1; //count to determine current data for each line
            
            
            while(getline(iss1, token, ' '))
            {
              
               //assign token to approriate variable
               switch (count)
               {
                  case 1:  //name strin
                     tempName = token;
                     break;
                  case 2:  //type char
                     tempType = token[0];
                     break;
                  case 3:  //row int
                     tempRow = stoi(token);
                     break;
   
               }//end switch
               
               count++;
            }//end inner while
            
            //verify that passenger is not a priority boarder
            if (!(tempRow == 10 || tempRow == 11 || tempRow < 5 || tempType == 'H' || tempType == 'E'))
            {  
               //then ccheck what row they are in, add them by group
               switch (i)
               {
                  case 1: 
                  {
                     if (tempRow >= 23 && tempRow <= 26)
                     {
                        tempKey = oldPriority;
                  
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                  
                  
                        Airworthy::oldQueue.add(newPassenger);
                        oldPriority--;
                     }//end case1
                     break;
                  }
                  case 2: 
                  {
                     if (tempRow >= 17 && tempRow <= 22)
                     {
                        tempKey = oldPriority;
                  
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                  
                  
                        Airworthy::oldQueue.add(newPassenger);
                        oldPriority--;
                     }
                     break;
                  }//end case2
                  case 3:
                  {
                     if (tempRow >= 11 && tempRow <= 16)
                     {
                        tempKey = oldPriority;
                  
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                  
                  
                        Airworthy::oldQueue.add(newPassenger);
                        oldPriority--;
                     }
                     break;
                  }//end case3
                  case 4:
                  {
                     if (tempRow >= 5 && tempRow <= 10)
                     {
                        tempKey = oldPriority;
                  
                        Passenger newPassenger(tempKey, tempName, tempType, tempRow);
                  
                  
                        Airworthy::oldQueue.add(newPassenger);
                        oldPriority--;
                     }
                     break;
                  }//end case4
               }//end switch
            }//end if
            
            iss1 >> token;
            //getline(inFile, line);    // read next line from file
         }//end outer while
      }//end for
      
   ////////////////////////////////////////////////////////////////////////////////
      //add the remaining general boarding passengers to newQueue
      inFile.clear();             //clear the buffer
      inFile.seekg(0, ios::beg);  //reset the reading position to beginning
      
      while (getline(inFile, line))//(inFile)
      {
         istringstream iss1 (line); //stringstream to parse input
         string token;               //variable to hold one word
         int count = 1; //count to determine current data for each line
         
         while(getline(iss1, token, ' '))
         {
           
            //assign token to approriate variable
            switch (count)
            {
               case 1:  //name string
                  tempName = token;
                  break;
               case 2:  //type char
                  tempType = token[0];
                  break;
               case 3:  //row int
                  tempRow = stoi(token);
                  break;

            }//end switch
            
            count++;
         }//end inner while
         
         //cout << "Before the if" << endl;
         
         //verify passenger is not in priority boarding, then add them
         if (!(tempRow == 10 || tempRow == 11 || tempRow < 5 || tempType == 'H' || tempType == 'E'))
         {
            tempKey = newPriority;
               
            Passenger newPassenger(tempKey, tempName, tempType, tempRow);
               
            Airworthy::newQueue.add(newPassenger);
            newPriority--;
            //cout << "During the if" << endl;
         }
         
         iss1 >> token;
         
      }//end outer while
      
      //close the file
      inFile.close();
      
      //reset priority to 0
      oldPriority = 0;
      newPriority = 0;
      
   } //test, end createQueues
   
/**************************************************************************************************************************************
 **************************************************************************************************************************************/ 
   
   /*
   * Simulates the 2 different boarding procedures for 3 pairs of queues, saving
   * the results, boarding order, and time to an ouput file
   */
   void Airworthy::runSimAll(int& f)
   {
      
      int prevRow;   //variable to hold previous passengers row
      
      Passenger tempPassenger;
      
      if (f == 1)
      {
         Passenger::outFile70 << endl << endl << "Boarding in Previous Procedure..." << endl << endl;
         Passenger::outFile70 << left;
         Passenger::outFile70 << fixed << "    " << setw(12) << "Last Name" << setw(5) << "Type";
         Passenger::outFile70 << setw(5) << "Row" << setw(5) << "Key" << endl;
      }
      else if (f == 2)
      {   
         Passenger::outFile85 << endl << endl << "Boarding in Previous procedure..." << endl << endl;
         Passenger::outFile85 << left;
         Passenger::outFile85 << fixed << "    " << setw(12) << "Last Name" << setw(5) << "Type";
         Passenger::outFile85 << setw(5) << "Row" << setw(5) << "Key" << endl;
      }
      else if (f == 3)
      { 
         Passenger::outFile100 << endl << endl << "Boarding in Previous procedure..." << endl << endl;
         Passenger::outFile100 << left;
         Passenger::outFile100 << fixed << "    " << setw(12) << "Last Name" << setw(5) << "Type";
         Passenger::outFile100 << setw(5) << "Row" << setw(5) << "Key" << endl;
      }
      
      //Save info to outputFile of first passenger, as long as queue is not empty, then remove them from the queue
      if (!(Airworthy::oldQueue.isEmpty()))
      {
         tempPassenger = Airworthy::oldQueue.peek();
         
         prevRow = tempPassenger.getRow();
         Airworthy::times += 1;
   
         tempPassenger.saveInfo(f);
         Airworthy::oldQueue.remove();
      }
      
      while (!(Airworthy::oldQueue.isEmpty()))
      {
         tempPassenger = Airworthy::oldQueue.peek();
         //If row of previous passenger is closer to front of plane then current passenger's row,
         //add 25 seconds. Otherwise add 1 second.
         if (tempPassenger.getRow() >= prevRow)
         {
            Airworthy::times += 25;
         }
         else
         {
            Airworthy::times += 1;
           
         }
         prevRow = tempPassenger.getRow();
         tempPassenger.saveInfo(f);
         Airworthy::oldQueue.remove();
      }
      
      //Save time to file and reset to 0.
      if (f == 1)
      {
         if (Passenger::outFile70)
         {
            Passenger::outFile70 << endl;
            Passenger::outFile70 << "    " << "Time to board: " << (times/60) << " minutes and " << (times%60) << " seconds";
            Passenger::outFile70 << endl << endl;
         }
         else
         cout << "Error: Output file not open." << endl << endl;
      }
      else if (f == 2)
      {   
         if (Passenger::outFile85)
         {
            Passenger::outFile85 << endl;
            Passenger::outFile85 << "    " << "Time to board: " << (times/60) << " minutes and " << (times%60) << " seconds";
            Passenger::outFile85 << endl << endl;
         }
         else
         cout << "Error: Output file not open." << endl << endl;
      }
      else if (f == 3)
      { 
         if (Passenger::outFile100)
         {
            Passenger::outFile100 << endl;
            Passenger::outFile100 << "    " << "Time to board: " << (times/60) << " minutes and " << (times%60) << " seconds";
            Passenger::outFile100 << endl << endl;
         }
         else
         cout << "Error: Output file not open." << endl << endl;
      }
      Airworthy::times = 0;
       
       //repeat for newer boarding method 
       
      if (f == 1)
      {
         Passenger::outFile70 << endl << "Boarding in Random Procedure..." << endl << endl;
         Passenger::outFile70 << left;
         Passenger::outFile70 << fixed << "    " << setw(12) << "Last Name" << setw(5) << "Type";
         Passenger::outFile70 << setw(5) << "Row" << setw(5) << "Key" << endl;
      }
      else if (f == 2)
      {   
         Passenger::outFile85 << endl << "Boarding in Random procedure..." << endl << endl;
         Passenger::outFile85 << left;
         Passenger::outFile85 << fixed << "    " << setw(12) << "Last Name" << setw(5) << "Type";
         Passenger::outFile85 << setw(5) << "Row" << setw(5) << "Key" << endl;
      }
      else if (f == 3)
      { 
         Passenger::outFile100 << endl << "Boarding in Random procedure..." << endl << endl;
         Passenger::outFile100 << left;
         Passenger::outFile100 << fixed <<"    " << setw(12) << "Last Name" << setw(5) << "Type";
         Passenger::outFile100 << setw(5) << "Row" << setw(5) << "Key" << endl;
      }
       
       
      if (!(Airworthy::newQueue.isEmpty()))
      {
         tempPassenger = Airworthy::newQueue.peek();
         
         prevRow = tempPassenger.getRow();
         Airworthy::times += 1;
         
         tempPassenger.saveInfo(f);
         Airworthy::newQueue.remove();
      }
      while (!Airworthy::newQueue.isEmpty())
      {
         tempPassenger = newQueue.peek();
         if (tempPassenger.getRow() >= prevRow)
         {
            Airworthy::times += 25;
         }
         else
         {
            Airworthy::times += 1;
         }
         prevRow = tempPassenger.getRow();
         tempPassenger.saveInfo(f);
         Airworthy::newQueue.remove();
      }
      //Save the time to the file and reset to 0
      if (f == 1)
      {
         if (Passenger::outFile70)
         {
            Passenger::outFile70 << endl;
            Passenger::outFile70 << "    " << "Time to board: " << (times/60) << " minutes and " << (times%60) << " seconds";
            Passenger::outFile70 << endl << endl;
         }
         else
         cout << "Error: Output file not open." << endl << endl;
      }
      else if (f == 2)
      {   
         if (Passenger::outFile85)
         {
            Passenger::outFile85 << endl;
            Passenger::outFile85 << "    " << "Time to board: " << (times/60) << " minutes and " << (times%60) << " seconds";
            Passenger::outFile85 << endl << endl;
         }
         else
         cout << "Error: Output file not open." << endl << endl;
      }
      else if (f == 3)
      { 
         if (Passenger::outFile100)
         {
            Passenger::outFile100 << endl;
            Passenger::outFile100 << "    " << "Time to board: " << (times/60) << " minutes and " << (times%60) << " seconds";
            Passenger::outFile100 << endl << endl;
         }
         else
         cout << "Error: Output file not open." << endl << endl;
      }
      Airworthy::times = 0;
      
      //close output files
      tempPassenger.closeOutputFiles(f);  
      
   } //end  runSimAll
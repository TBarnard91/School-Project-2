/**
 * @file Passenger.cpp 
 * @author Tyler Barnard
 * @date  November 23, 2018
 * @class Passenger
 * The object to be stored in the PriorityQueue. Represents a single passenger on the plane.
 * It includes 
 */

#include "Passenger.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
   
   ofstream Passenger::outFile30(OUTPUT_FILE_30.c_str());  // open output files
   ofstream Passenger::outFile70(OUTPUT_FILE_70.c_str());
   ofstream Passenger::outFile85(OUTPUT_FILE_85.c_str());
   ofstream Passenger::outFile100(OUTPUT_FILE_100.c_str());
   
   /**
    * Default constructor
    */
   Passenger::Passenger()
   {
   
   }//end default constructor

   /**
    * Overloaded constructor
    * @param newPriority - value for passenger's priority, the key
    * @param newName  - passenger's name
    * @param newType - passenger's type
    * @param newRow - passenger's row
    */
   Passenger::Passenger( const int& newKey, const string& newName,
            const char& newType, const int& newRow)
   {
      key = newKey;
      name = newName;
      type = newType;
      row = newRow;
   }//end overloaded constructor
            
   /**
    * Accessor for the priority.
    * @return priority of this passenger, the key
    */
   int Passenger::getKey(void)
   {
      return key;
   }
   
   /**
    * Mutator for the priority.
    * @param newPriority - priority of this passenger, the key
    */
   void Passenger::setKey(int& newKey)
   {
      key = newKey;
   }
   
   /**
    * Accessor for the name.
    * @return name of this passenger
    */
   string Passenger::getName(void)
   {
      return name;
   }
   
   /**
    * Mutator for the name.
    * @param newTitle - name of this passenger
    */
   void Passenger::setName(string& newName)
   {
      name = newName;
   }
   
   /**
    * Accessor for the type.
    * @return type of this passenger
    */
   char Passenger::getType(void)
   {
      return type;
   }
   
   /**
    * Mutator for the type.
    * @param newType - type of this passenger
    */
   void Passenger::setType(char& newType)
   {
      type = newType;
   }
   
   /**
    * Accessor for the row.
    * @return row of this passenger
    */
   int Passenger::getRow(void)
   {
      return row;
   }
   
   /**
    * Mutator for the row.
    * @param newRow - row of this passenger
    */
   void Passenger::setRow(int& newRow)
   {
      row = newRow;
   }
   
   /**
    * Defines the > operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using >
    */
   bool Passenger::operator> (const Passenger &right)
   {
      return (key > right.key);
   }

   /**
    * Defines the < operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using <
    */
   bool Passenger::operator< (const Passenger &right)
   {
      return (key < right.key);
   }
   
   /**
    * Displays all the data stored for the passenger.
    */
   void Passenger::printInfo(void)
   {
      cout<< "    " << name << " " << type << " " << row << " " << key << endl;
   }
  
   /**
    * Saves all the data stored for the passenger to a file.
    * @parm f - int for switch statement, determines which output file to save data to
    */
   void Passenger::saveInfo(int& f)
   {  
      switch (f)
      {
         case 1:
         {
            if (outFile70)
            {
               outFile70 << left;
               outFile70 << fixed << "    " << setw(12) << name << setw(5) << type << setw(5) << row << setw(5) << key << endl;
            }
            else
            cout << "Error: Output file not open." << endl << endl;
         }
            break;
         case 2:
         {
            if (outFile85)
            {
               outFile85 << left;
               outFile85 << fixed << "    " << setw(12) << name << setw(5) << type << setw(5) << row << setw(5) << key << endl;
            }
            else
            cout << "Error: Output file not open." << endl << endl;
         }
            break;
         case 3:   
         {
            if (outFile100)
            {
               outFile100 << left;
               outFile100 << fixed << "    " << setw(12) << name << setw(5) << type << setw(5) << row << setw(5) << key << endl;
            }
            else
            cout << "Error: Output file not open." << endl << endl;
         }
            break;
      }//end switch 
   }//end saveInfo
      
   /**
    * Closes the output files
    * param f - the output file to be closed
    */
   void Passenger::closeOutputFiles(int& f)
   {
      if (f == 1)
      {
         outFile70.close();
      }
      else if (f == 2)
      {
         outFile85.close();
      }
      else if (f == 3)
      {
         outFile100.close();
      }
   }//end closeOutputFiles
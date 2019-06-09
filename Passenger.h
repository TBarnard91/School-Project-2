/**
 * @file Passenger.h 
 * @author Tyler Barnard
 * @date  November 23, 2018
 * @class Passenger
 * The object to be stored in the PriorityQueue. Represents a single passenger on the plane.
 * It includes the Name, Row number, Type of passenger, and Key value.
 */
#ifndef PASSENGER_H

#include <string>
#include <fstream>
using namespace std;

   
   // Name of the files to store simulation data
   const string OUTPUT_FILE_30 = "results30.txt";
   const string OUTPUT_FILE_70 = "results70.txt";
   const string OUTPUT_FILE_85 = "results85.txt";
   const string OUTPUT_FILE_100 = "results100.txt";
   

class Passenger
{
private:
   int key;       // Passenger priority level, the key
   string name;   // Passenger's last name
   char type;     /* Passenger type ('H' is child or passenger who needs help boarding,
                     'E' is an elite passenger(frequent flyer), 'G' is general boarding */
   int row;       // Row in which the passenger is to be seated.

	 
public:

	 //Output files to store the data for a passenger
	 static ofstream outFile30;
    static ofstream outFile70;
    static ofstream outFile85;
    static ofstream outFile100;
    
   /**
    * Default constructor
    */
   Passenger();

   /**
    * Overloaded constructor
    * @param newKey - value for passenger's priority, the key
    * @param newName  - passenger's name
    * @param newType - passenger's type
    * @param newRow - passenger's row
    */
   Passenger( const int& newKey, const string& newName,
            const char& newType, const int& newRow);
   
   /**
    * Accessor for the priority.
    * @return priority of this passenger, the key
    */
   int getKey(void);
   
   /**
    * Mutator for the key.
    * @param newKey - priority of this passenger, the key
    */
   void setKey(int& newKey);
   
   /**
    * Accessor for the name.
    * @return name of this passenger
    */
   string getName(void);
   
   /**
    * Mutator for the name.
    * @param newTitle - name of this passenger
    */
   void setName(string& newName);
   
   /**
    * Accessor for the type.
    * @return type of this passenger
    */
   char getType(void);
   
   /**
    * Mutator for the type.
    * @param newType - type of this passenger
    */
   void setType(char& newType);
   
   /**
    * Accessor for the row.
    * @return row of this passenger
    */
   int getRow(void);
   
   /**
    * Mutator for the row.
    * @param newRow - row of this passenger
    */
   void setRow(int& newRow);
   
   /**
    * Defines the > operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using >
    */
   bool operator> (const Passenger &right);

   /**
    * Defines the < operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using <
    */
   bool operator< (const Passenger &right);
   
   /**
    * Displays all the data stored for the passenger.
    */
   void printInfo(void);
   
   /**
    * Saves all the data stored for the passenger to a file.
    * @param f - int for switch statement, determines which output file to save data to
    */
   void saveInfo(int& f);
   
   /**
    * Closes the output files
    * param f - the output file to be closed
    */
   void closeOutputFiles(int& f);
   
}; // end Student
#define PASSENGER_H
#endif
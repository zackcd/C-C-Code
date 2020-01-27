// Name: Zack Downing
// USC NetID: zdowning
// CSCI 455 PA5
// Spring 2018

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

void tableInsert(Table & grades);
void tableChange(Table & grades);
void tableLookup(Table & grades);
void tableRemove(Table & grades);
void help();
void readVals(string & name, int & score);

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);


  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*
    string input = "";
    while(input != "quit") {
        cout << "cmd>";
        cin >> input;
        
        if(input == "insert") {
            //tableInsert(*grades);
                string name;
                int score;
                readVals(name, score);
                if(grades->lookup(name)) {
                    cout << "Name is already present." << endl;
                }
                else
                    grades->insert(name, score);
        }
        else if(input == "change")
            tableChange(*grades);
        
        else if(input == "lookup")
            tableLookup(*grades);
        
        else if(input == "remove")
            tableRemove(*grades);

        else if(input == "print")
            grades->printAll();
        
        else if(input == "size")
            cout << grades->numEntries() << endl;
        
        else if(input == "stats")
            grades->hashStats(cout);
        
        else if(input == "help")
            help();
        
        else if(input == "quit")
            return 0;
        
        else {
            cout << "ERROR: invalid command" << endl;
            help();
        }
    }

  return 0;
}

//Helper function to insert a name and grade in the table
void tableInsert(Table & grades) {
    string name;
    int score;
    readVals(name, score);
    if(grades.lookup(name)) {
        cout << "Name is already present." << endl;
    }
    else
        grades.insert(name, score);
}

//Helper function to change a grade in the table, given a target key
void tableChange(Table & grades) {
    string target;
    int newScore;
    readVals(target, newScore);
    
    int * lookup = grades.lookup(target);
    if(lookup == NULL)
        cout << "Student name not present" << endl;
    else
        *lookup = newScore;
}

//Helper function to remove a node with the given target key
void tableRemove(Table & grades) {
    string target;
    cin >> target;
    if(!grades.lookup(target)) {
        cout << "Name is not present." << endl;
    }
    else
        grades.remove(target);
}

//Helper function to perform a lookup in the table given a target key
void tableLookup(Table & grades) {
    string target;
    cin >> target;
    int * lookup = grades.lookup(target);
    if(lookup == NULL)
        cout << "Student name not present" << endl;
    else {
        cout << "Score: " << *lookup << endl;
    }
}

//Helper function for above helper functions to read in values
void readVals(string & name, int & score) {
    cin >> name;
    cin >> score;
}

//Helper function to print list of commands
void help() {
    cout << "Enter 'insert' to insert a name and score." << endl;
    cout << "Enter 'change' to change the score for a name." << endl;
    cout << "Enter 'lookup' to lookup the score for a name." << endl;
    cout << "Enter 'remove' to remove a name entry." << endl;
    cout << "Enter 'print' to print all names and scores." << endl;
    cout << "Enter 'size' to print the number of entries." << endl;
    cout << "Enter 'stats' to get statistics about the hash table at this point." << endl;
    cout << "Enter 'help' for a command summary." << endl;
    cout << "Enter 'quit' to exit the program." << endl;
}













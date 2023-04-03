// hashTable.cpp : Defines the entry point for the console application.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// Defaults in solution folder
string inputFileNameStr = "namesids.txt";

//define namePair using C++  pair template class (2 strings - first & last name)
typedef pair<string, string> namePair;

//define stl::hash function for namePair keys
namespace std {

    template <> class hash <namePair> {
    public:
        size_t operator() (const namePair& namePair) const {
            return hash<string>() (namePair.first) ^ hash<string>() (namePair.second);
        }//size_t operator()
    };//class hash

}//namespace std


void displayHashTableLookupResult(pair<string, string> namePair, unordered_map<pair<string, string>, unsigned int>& hashTable) {

    stringstream stringStreamObj;

    stringStreamObj << setw(20) << left << namePair.first << setw(20) << left << namePair.second;
    cout << stringStreamObj.str();
    if (hashTable[namePair])
        cout << setw(29) << left << hashTable[namePair] << endl;
    else
        cout << "There is no hash table entry" << endl;

};


int main(int argc, char* argv[]) {

  //define hashTable as namepair keys and integer value identifications (open address linear probe)
    unordered_map<namePair, unsigned int> hashTable;

  //Put in the hash table the namePair keys and associated number ids from text file
    ifstream inputFileStreamObj;

    inputFileStreamObj.open(inputFileNameStr, ios::in);
    if (inputFileStreamObj.fail()) {
        cout << "File could not be opened!" << endl;
        return (EXIT_FAILURE);
    }

    string   firstName, lastname;
    unsigned id;

    while (inputFileStreamObj) {
        inputFileStreamObj >> firstName >> lastname >> id;
        hashTable[namePair(firstName, lastname)] = id;
    }

    for (pair<namePair, unsigned int> element : hashTable) {
        cout << setw(20) << left << element.first.first;
        cout << setw(20) << left << element.first.second;
        cout << setw(20) << left << element.second << endl;
    }

    cout << endl << endl;

    displayHashTableLookupResult(namePair("Melania", "Knavs"), hashTable);
    displayHashTableLookupResult(namePair("Marshal", "Mathers"), hashTable);
    displayHashTableLookupResult(namePair("Peter", "Hernandez"), hashTable);
    displayHashTableLookupResult(namePair("Jon", "Snow"), hashTable); // not in table
    displayHashTableLookupResult(namePair("Monica", "Lewinsky"), hashTable);
    displayHashTableLookupResult(namePair("Rick", "Sanchez"), hashTable); // not in table

    return 0;
}


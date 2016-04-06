// Definition of Datastructure class for UDS/Tiraka homework 1 -
#ifndef DATASTRUCTURE_HH
#define DATASTRUCTURE_HH
#include <string>
#include <vector>
#include<algorithm>
#include <iostream>
#include <cstdlib>
struct person_list
{
  std::string  rank;
  unsigned int birthYear;
  unsigned int enlistingYear;
  std::string  shirtColor;
  std::string  name;
};

const char SEPARATOR = ' ';
const std::string MSG_EMPTY_DS = "Data structure is empty.\n";

class Datastructure {

public:

   Datastructure();

   ~Datastructure();

   // Adds one value to the datastructure
   void add(std::string rank, unsigned int birthYear, unsigned int enlistingYear, std::string shirtColor, std::string name);

   // Finds and prints person with index
   void find(unsigned int index);

   // Finds and prints youngest person
   void youngest();

   // Finds and prints oldest person
   void oldest();

   // Empties the datastructure
   void empty();

   // returns the size of the datastructure
   size_t size();

   int random_partition(std::vector<person_list>& person, int start, int end);


   void my_random_quick_sort(std::vector<person_list>& person, int start,int end);

private:

   // Copy constructor is forbidden
   Datastructure(const Datastructure&);
   // Assignment operator is forbidden
   Datastructure& operator=(const Datastructure&);

};
#endif

// Author : Armand Thierry djappi, October 2014 
//this is the file where you'll write implementation of the datastructure
using namespace std;
#include "datastructure.hh"
extern std::vector<person_list> person;
std::vector<person_list> person;

//person_list temp2;

Datastructure::Datastructure()
{

}

Datastructure::~Datastructure()
{

}

void Datastructure::add(std::string rank, unsigned int birthYear, unsigned int enlistingYear, std::string shirtColor, std::string name)
{
 if (!cin.fail())
 {

  person.push_back(person_list());
  person.back().rank          = rank;
  person.back().birthYear     = birthYear;
  person.back().enlistingYear = enlistingYear;
  person.back().shirtColor    = shirtColor;
  person.back().name          = name;

 }
 else
 {
  if (std::cin.eof())
  {
   std::cin.clear() ;
  }
 }
}

void Datastructure::find(unsigned int index)
{
 bool find1                   = false;

 if ((unsigned int)person.size()>0)
 {
  if (index>0 && index<=(unsigned int)person.size())
  {
   if ((unsigned int)person.size()-1>0)
   {
    if(find1==false)
    {
     my_random_quick_sort(person,0,person.size()-1);
     find1                    = true;
    }
   }
  std::cout << person[index-1].name<<SEPARATOR<<person[index-1].rank<<SEPARATOR<<person[index-1].birthYear<<SEPARATOR<<person[index-1].enlistingYear<<SEPARATOR<<person[index-1].shirtColor<<'\n';
  }
  else
  {
   std::cout << "Out of range.";
  }
 }
 else
 {
  std::cout<< MSG_EMPTY_DS;
 }
}

size_t Datastructure::size()
{
return person.size();
}

void Datastructure::empty()
{
  if ((unsigned int)person.size()>0)
  {
    person.clear();  // clear all the element
    std::vector<person_list>().swap(person); // erase capacity allocate to that vector
  }
}

void Datastructure::oldest()
{
 if ((unsigned int)person.size()>0)
 {
 unsigned int pivot_index = (unsigned int)(rand() % (int)person.size());  //generates a random number as the pivot
 unsigned int pivot       = person[pivot_index].enlistingYear; // the pivot is a random element

  for (unsigned int i=0; i<(unsigned int)person.size(); i++)
  {
   if (
       ((unsigned int)person[i].enlistingYear<pivot && i!=pivot_index)
                                             ||
       ((unsigned int)person[i].enlistingYear==pivot && i!=pivot_index && (unsigned int)person[i].birthYear<((unsigned int)person[pivot_index].birthYear) )
     )
   {

   pivot_index            = i;
   pivot                  = person[pivot_index].enlistingYear;
   }
  }
 std::cout << person[pivot_index].name<<SEPARATOR<<person[pivot_index].rank<<SEPARATOR<<person[pivot_index].birthYear<<SEPARATOR<<person[pivot_index].enlistingYear<<SEPARATOR<<person[pivot_index].shirtColor<<'\n';
 }
 else
 {
 std::cout<< MSG_EMPTY_DS;
 }
}

void Datastructure::youngest()
{
 unsigned int pivot_index = (unsigned int)(rand() % (int)person.size());  //generates a random number as the pivot
 unsigned int pivot       = person[pivot_index].enlistingYear; // the pivot is a random element
 if ((unsigned int)person.size()>0)
 {
  for (unsigned int i=0; i<(unsigned int)person.size(); i++)
  {
   if (
       ((unsigned int)person[i].enlistingYear>pivot && i!=pivot_index)
                                             ||
       ((unsigned int)person[i].enlistingYear==pivot && i!=pivot_index && (unsigned int)person[i].birthYear>((unsigned int)person[pivot_index].birthYear) )
     )
   {

   pivot_index            = i;
   pivot                  = person[pivot_index].enlistingYear;
   }
  }
 std::cout << person[pivot_index].name<<SEPARATOR<<person[pivot_index].rank<<SEPARATOR<<person[pivot_index].birthYear<<SEPARATOR<<person[pivot_index].enlistingYear<<SEPARATOR<<person[pivot_index].shirtColor<<'\n';
 }
 else
 {
 std::cout<< MSG_EMPTY_DS;
 }
}

// new quick sort with external partition
int Datastructure::random_partition(std::vector<person_list>& my_list, int start, int end)
{
    unsigned int pivotIdx = (unsigned int)start + (unsigned int) (rand()%(end - start+1));
    swap(my_list[pivotIdx], my_list[(unsigned int) end]); // move pivot element to the end
    pivotIdx              = (unsigned int) end;
    unsigned int        i = (unsigned int) start -1;

    for(unsigned int j=(unsigned int)start; j<=(unsigned int) (end-1); j++)
    {
        if(((my_list[j].enlistingYear<my_list[pivotIdx].enlistingYear))
                                      ||
          ((my_list[j].enlistingYear==my_list[pivotIdx].enlistingYear) && (my_list[j].birthYear<my_list[pivotIdx].birthYear))
                                      ||
          ((my_list[j].enlistingYear==my_list[pivotIdx].enlistingYear) && (my_list[j].birthYear==my_list[pivotIdx].birthYear)))
          {
            i = i+1;
            swap(my_list[i], my_list[j]);
          }
    }
    swap(my_list[i+1], my_list[pivotIdx]);
    return  (int) (i+1);
}


void Datastructure::my_random_quick_sort(std::vector<person_list>& my_list, int start, int end)
{
    if(start <end) {
       int mid =  random_partition( my_list, start, end);
        my_random_quick_sort(my_list, start, mid-1);
        my_random_quick_sort(my_list, mid+1, end);
    }
}

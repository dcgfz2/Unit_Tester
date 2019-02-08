#ifndef LIST_H
#define LIST_H

#include <stdexcept>
using namespace std;

template <class T>
struct Cell
{
  T elem;
  Cell *next;

  // Constructors
  Cell(const T &t, Cell *n);
  Cell(const Cell &c);
};

template <class T>
class List
{

public:
  // Constructor
  List();

  // Copy Constructor
  List(const List &l);

  // Destructor
  ~List();

  // Inserting stuff
  void prepend(const T &t); // Adds items to the beginning of the List
  void append(const T &t);  // Adds items to the end of the List

  // Removing stuff
  void pop(); // Removes one item from the front of the List

  // Accessors
  T &head();   // Returns a reference to the first element
  List tail(); // Returns a copy of everything except the first element

  Cell<T> *iterator();

  // Properties
  unsigned int length() const; // Returns the length of the List
  bool empty() const;          // Returns true if empty

private:
  Cell<T> *cell;
};

#include "list.hpp"
#endif

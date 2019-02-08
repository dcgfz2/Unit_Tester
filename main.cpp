#include <iostream>
#include "list.h"
using namespace std;

int main()
{
  List<int> l;

  // Add 10 ints to the List
  for (int i = 0; i < 10; i++)
  {
    l.append(i);
  }

  // Pop the first item out
  l.pop();

  // Walk down the items in the List
  Cell<int> *it = l.iterator();
  while (it != NULL)
  {
    cout << it->elem << endl;
    it = it->next;
  }

  return 0;
}

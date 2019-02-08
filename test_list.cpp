#include <boost/test/unit_test.hpp>

#include <stdexcept>
#include "list.h"

BOOST_AUTO_TEST_SUITE(list)

struct explore
{
  List<int> empty;
  List<int> t1;
  List<int> t2;

  explore()
  {
    for(int i = 0; i < 10; i++)
    {
      t1.prepend(i);
    }
    for(int i = 0; i < 15; i++)
    {
      t2.append(i);
    }
  }
};

BOOST_FIXTURE_TEST_CASE(def_construct, explore)
{
  BOOST_CHECK_EQUAL(empty.empty(),true);
  BOOST_CHECK_EQUAL(empty.length(),0);
  BOOST_CHECK_EQUAL(t1.empty(),false);
  BOOST_CHECK_EQUAL(t1.length(),10);
  BOOST_CHECK_EQUAL(t2.empty(),false);
  BOOST_CHECK_EQUAL(t2.length(),15);
}

BOOST_FIXTURE_TEST_CASE(copy_construct, explore)
{
  List<int> temp(t2);

  BOOST_CHECK_EQUAL(t2.length(),temp.length());
  BOOST_CHECK_EQUAL(t2.head(),temp.head());
  
  Cell<int>* trv = t2.iterator();
  Cell<int>* trv2 = temp.iterator();
  
  while(trv != NULL)
  {
    BOOST_CHECK_EQUAL(trv->elem,trv2->elem);
    trv = trv->next;
    trv2 = trv2->next;
  }
  //Checks for deep copy
  temp.pop();
  BOOST_CHECK_NE(t2.head(),temp.head());
}
  
BOOST_FIXTURE_TEST_CASE(prepend, explore)
{
  int desend = 9;
  Cell<int>* next = t1.iterator();
  while(next != NULL)
  {
    BOOST_CHECK_EQUAL(desend,next->elem);
    desend--;
    next = next->next;
  }
}

BOOST_FIXTURE_TEST_CASE(append, explore)
{
  int assend = 0;
  Cell<int>* traverse = t2.iterator();
  while(traverse != NULL)
  {
    BOOST_CHECK_EQUAL(assend,traverse->elem);
    assend++;
    traverse = traverse->next;
  }
}

BOOST_FIXTURE_TEST_CASE(pop, explore)
{
  List<int>temp3(t1);
  
  temp3.pop();
  Cell<int>* second = t1.iterator();
  second = second->next;
  
  BOOST_CHECK_EQUAL(second->elem,temp3.head());
  BOOST_CHECK_GE(t1.length(),temp3.length());
  
  BOOST_CHECK_THROW(empty.pop(), out_of_range); 
}

BOOST_FIXTURE_TEST_CASE(head, explore)
{
  List<char> ap_1;
  List<char> pre_1;

  ap_1.append('b');
  pre_1.prepend('n');

  BOOST_CHECK_EQUAL(ap_1.head(),'b');
  BOOST_CHECK_EQUAL(pre_1.head(),'n');

  ap_1.append('z');
  pre_1.prepend('z');
  
  BOOST_CHECK_EQUAL(ap_1.head(),'b');
  BOOST_CHECK_EQUAL(pre_1.head(),'z');
  
  BOOST_CHECK_THROW(empty.head(), out_of_range);
}

BOOST_FIXTURE_TEST_CASE(tail, explore)
{
  List<string> tester1;

  tester1.append("Is");
  tester1.append("This");
  tester1.append("Extremely");
  tester1.append("Mundane");

  List<string> tester2(tester1);
  List<string> tester3 = tester1.tail();

  tester2.pop();
  
  BOOST_CHECK_EQUAL(tester2.head(),tester3.head());
  BOOST_CHECK_EQUAL(tester2.length(),tester3.length());
  
  BOOST_CHECK_THROW(empty.tail(), out_of_range);
}

BOOST_FIXTURE_TEST_CASE(length, explore)
{
  BOOST_CHECK_EQUAL(empty.length(),0);
  BOOST_CHECK_EQUAL(t1.length(),10);
  BOOST_CHECK_EQUAL(t2.length(),15);
}

BOOST_FIXTURE_TEST_CASE(empty, explore)
{
  List<int> emp;

  BOOST_CHECK_EQUAL(emp.length(),0);
}
BOOST_AUTO_TEST_SUITE_END()

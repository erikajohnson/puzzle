#include "puzzle_move.h"
#include "pmminlist.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds a PuzzleMove* to the internal list in sorted
 * order from smallest to largest
 * @param pm PuzzleMove* to add to the sorted PuzzleMove* list
 */
void PMMinList::push(PuzzleMove* pm)
{
  std::list<PuzzleMove*>::iterator it = slist_.begin();
 
  //---- Add your implementation to iterate through the list
  //---- to find the correct location to insert pm and then
  //---- use the insert() method of std::List to insert it
  //---- See http://www.cplusplus.com/reference/list/list/insert/

  if (slist_.empty()){
    slist_.insert(it,pm);
    return;
  }

  for (it=slist_.begin(); it != slist_.end(); ++it){
    if (*pm < **it){
      slist_.insert(it,pm);
      return;
    }
  }

  slist_.push_back(pm);
}

/**
 * Removes PuzzleMove* from beginning of sorted PuzzleMove* list (i.e.
 * minimum-scored PuzzleMove*)
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Gets PuzzleMove* from beginning of sorted PuzzleMove* list
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}


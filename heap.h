#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int ary;
  PComparator comp;
  std::vector<T> vec;
  
  void heapifyUp() {
    int i = size()-1;  // last node

    while (i > 0) {
      int parI = (i-1)/ary;  // parent of i

      if (comp(vec[i], vec[parI])) 
        std::swap(vec[i], vec[parI]);  // if i is better than its parent, swap

      else  // parent is better so i cannot move up anymore
        break;

      i = parI;
    }
  }

  void heapifyDown() {
    int i = 0;  // root
    while (true) {
      int firstChildI = ary*i + 1;  // +1 bc we index from 0
      if (firstChildI >= size())   // if there are no children
        break;

      int bestChildI = firstChildI;
      for (int x = 2; x < ary+1; x++) {  // loop through all children and find the best
        int y = ary*i + x;

        if (y >= size())  // no more children
          break;

        if (comp(vec[y], vec[bestChildI]))  // compare current child with best
          bestChildI = y;
      }

      if (comp(vec[bestChildI], vec[i]))  //if best child is better than parent, swap
        std::swap(vec[bestChildI], vec[i]);
        
      else 
        break;

      i = bestChildI;
    }
  }

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  ary = m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  vec.push_back(item);
  heapifyUp();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return vec.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return vec.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  // swap first and last
  std::swap(vec[0], vec[size()-1]);
  vec.pop_back();
  heapifyDown();
}



#endif


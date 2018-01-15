# Container class templates
## Sequence containers:
+ array (c++11)
+ vector
+ deque
+ forward_list (c++11)
+ list

## Container adaptors:
+ stack (LIFO)
+ queue (FIFO)
+ priority_queue

## Associative containers:
+ set
+ multiset
+ map
+ multimap

## Unordered associative containers:
(c++11)
+ unordered_set
+ unordered_multiset
+ unordered_map
+ unordered_multimap

## Vector
Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.

Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity.

Therefore, compared to arrays, **vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.**

Compared to the other dynamic sequence containers (deques, lists and forward_lists), **vectors are very efficient accessing its elements** (just like arrays) **and relatively efficient adding or removing elements from its end**. *For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.*

### Member functions
>*Unless specified another thing, the following are public member functions.*

+ **(constructors)** Constructs vector:
~~~c++
  vector<int> first;                                // empty vector of ints
  vector<int> second (4,100);                       // four ints with value 100
  vector<int> third (second.begin(),second.end());  // iterating through second
  vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); // o vector<int> fifth(myints, myints+4);
~~~
+ **~vector** Vector destructor

+ **operator=** Assign content
~~~c++
  vector<int> foo (3,0);
  vector<int> bar (5,0);

  bar = foo;
  foo = vector<int>();

  cout << "Size of foo: " << int(foo.size()) << '\n'; // returns 0
  cout << "Size of bar: " << int(bar.size()) << '\n'; //returns 3
~~~

---------------Iterators:

+ **begin()**
    Return iterator to beginning

+ **end()**
    Return iterator to end

+ **rbegin()**
    Return reverse iterator to reverse beginning

+ **rend()**
    Return reverse iterator to reverse end

They all have constant complexity.

(c++11)

+ **cbegin()**
    Return const_iterator to beginning

+ **cend()**
    Return const_iterator to end

+ **crbegin()**
    Return const_reverse_iterator to reverse beginning

+ **crend()**
    Return const_reverse_iterator to reverse end

Example:
~~~c++
// vector::begin/end
#include <iostream>
#include <vector>
using namespace std;

int main () {
  vector<int> myvector;
  for (int i=1; i<=5; i++)
    myvector.push_back(i);

  cout << "myvector contains:";
  for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    cout << ' ' << * it;
  cout << '\n';
}
~~~

~~~c++
// vector::rbegin/rend
#include <iostream>
#include <vector>
using namespace std;

int main () {
  vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  vector<int>::reverse_iterator rit;
  for (rit= myvector.begin(); rit!= myvector.rend(); ++rit)
    * rit = ++i;

  cout << "myvector contains:";
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    cout << ' ' << * it;
  cout << '\n';
}

//Output:
//myvector contains: 5 4 3 2 1
~~~

---------------Capacity:

+ **size()** Return size. Constant complexity.

+ **max_size()** Return maximum size . Constant complexity.

+ **resize(size_type n, T val = value_type())**
    Change size. Complexity: Linear on the number of elements inserted/erased (constructions/destructions). If a reallocation happens, the reallocation is itself up to linear in the entire vector size. If val is not specified, 0 is used.
    ~~~c++
    vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    cout << "myvector contains:";
    for (int i= 0;i< myvector.size();i++)
      cout << ' ' << myvector[i];
    cout << '\n';

    //Output:
    //myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
    ~~~


+ **capacity()**
    Return size of allocated storage capacity

+ **empty()**
    Test whether vector is empty. Constant complexity.

+ **reserve(size_type n)**
    Request a change in capacity. Complexity: If a reallocation happens, linear in vector size at most.

+ **shrink_to_fit()**
    Requests the container to reduce its capacity to fit its size.(c++11)


---------------Element access:

+ **operator[](size_type n)**
    Returns (const)reference to element at position n. vector::at, has the same behavior as this operator function, except that vector::at is bound-checked and signals if the requested position is out of range by throwing an out_of_range exception.

    Portable programs should never call this function with an argument n that is out of range, since this causes undefined behavior. Constant complexity.

+ **at(size_type n)**
    Returns (const)reference to element at position n. Constant complexity.

+ **front()**
    Returns (const)reference to first element. Constant complexity.

+ **back**
    Returns (const)reference to last element. Constant complexity.

+ **data**
    Access data (c++11)


---------------Modifiers:

+ **assign**
    Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly. Complexity: Linear on initial and final sizes (destructions, constructions).
    Additionally, in the range version `void assign(InputIterator first, InputIterator last)`, if InputIterator is not at least of a forward iterator category (i.e., it is just an input iterator) the new capacity cannot be determined beforehand and the operation incurs in additional logarithmic complexity in the new size (reallocations while growing).
    ~~~c++

    vector<int> first;
    vector<int> second;
    vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100

    vector<int>::iterator it;


    second.assign (first.begin(),first.end()); // assigning from another vector by means of iterators. Can be used with other containers, too.

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.
    ~~~

+ **push_back()**
    Add element at the end

+ **pop_back()**
    Delete last element

+ **insert()**
    Insert elements. Headers: `iterator insert (iterator position, const value_type& val);`, `void insert (iterator position, size_type n, const value_type& val);`, `void insert (iterator position, InputIterator first, InputIterator last);`. The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.

    This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.

    Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).

+ **erase()**
    Erase elements

+ **swap**
    Swap content

+ **clear**
    Clear content

+ **emplace**
    Construct and insert element (c++11). `iterator emplace (const_iterator position, Args&&... args);`

    The container is extended by inserting a new element at position. This new element is constructed in place using args as the arguments for its construction.

    This effectively increases the container size by one.

    An automatic reallocation of the allocated storage space happens if -and only if- the new vector size surpasses the current vector capacity.

    *Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to shift all the elements that were after position by one to their new positions. This is generally an inefficient operation compared to the one performed by other kinds of sequence containers (such as list or forward_list).**

    A similar member function exists, insert, which either copies or moves existing objects into the container.

**emplace_back**
    Construct and insert element at the end (c++11)


---------------Allocator:

**get_allocator**
    Get allocator (public member function )


---------------Non-member function overloads

**relational operators**
    Relational operators for vector (function template )

**swap**
    Exchange contents of vectors (function template )


---------------Template specializations

**vector<bool>**
    Vector of bool (class template specialization )

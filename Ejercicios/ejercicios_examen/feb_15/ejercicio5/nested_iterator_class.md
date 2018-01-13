# How to implement a nested iterator class
#### Source: http://www.cplusplus.com/forum/beginner/184965/
**Question:** Im having a very hard time wrapping my mind around this nested
iterator class within a Vector class. I've written the Vector class myself,
so I understand that myself. However, the iterator class within the Vector
class was written by my professor.

I've used iterators before, but I dont understand how this nested iterator
class works? Can I get a line-by-line breakdown and an example of how this
code would be used in the main function? I would really appreciate it.
~~~c
template<class T>
class Vector{
   private:
       T* arr;
       int size;
       int capacity;

       // expands array when all space is take up
       void grow(){
           capacity*=2;
           T* temp = new T[capacity];

           for(int i=0; i<size; i++)
               temp[i] = arr[i];

           delete [] arr;
           arr = temp;
       }

   public:
       // Default constructor
       Vector(){
          size = 0;
          capacity = 10;
          arr = new T[capacity];
       }

       // 2-Parameter constructor
       Vector(int n, const T& elt){
           size = n;
           capacity = 2*n;
           arr = new T[capacity];

           for(int i = 0; i < size; i++)
               arr[i] = elt;
       }

       // returns size of vector
       int Size(){
           return size;
       }

       // adds element to the back of the vector
       void push_back(const T& elt){
           if(size == capacity) grow();

           arr[size] = elt;
           size++;
       }

       // removes element from the back of the vector
       void pop_back(){
           if(size>=1)
               size--;
       }

       // returns reference to element at position pos
       T& at(int pos){
           if(pos>0 && pos<size)
               return arr[pos];
       }

       // returns reference to element at fron of vector
       T& front(){
           if(size >= 1)
               return arr[0];
       }

       // returns reference to element at back of vector
       T& back(){
           if(size >= 1)
               return arr[size-1];
       }

       // returns true if vector is empty, else returns false
       bool empty(){
           if(size == 0)
               return true;
           else return false;
       }

       void insert(const T& elt, int pos){
           if(size == capacity) grow();

           for(int i=size; i>pos; i--)
              arr[i] = arr[i-1];

           arr[pos] = elt;
           size++;
       }

       void erase(int pos){
           for(int i = pos; i<size-1; i++)
               arr[i] = arr[i+1];

           size--;
       }

       // Here is where the nested class begins
       class iterator{
           int i;
           Vector<T>& parent; // im confused by this especially

           public: // what is the purpose of this constructor?
               iterator(Vector<T>& v, int pos): parent(v), i(pos){}

           T& operator*(){
               return parent[i]; // why do we return this?
           }

           iterator& operator++(){
               iterator* temp = this;
               i++;
               return temp;
           }
       };

};
~~~

**Answer:** An iterator is basically a pointer to an element in a container.
~~~c
/*
Reference to a Vector of any type as an iterator needs
a container to iterate through.
*/
Vector<T>& parent;

/*
This is to initialise member variables.
*/
public:
               iterator(Vector<T>& v, int pos): parent(v), i(pos){}

/*
As I mentioned above, an iterator is a pointer. When you do *ptr
you retrieve the value that is stored at ptr.
Likewise with this; you retrieve the value currently stored at the
iterator.
*/
T& operator*()
{
      return parent[i];
}
~~~

**Q:**
I know an iterator is a pointer, I've used them before. Im just trying to
understand their class implementation.

How does `Vector<T>& parent` 'connect' the iterator class to the Vector class?

Regarding the constructor: I've never seen an iterator declared with parameters.
This is what I've normally seen: `Vector<int>::iterator it;`

No parameters are being passed. I've tried this in main and it wont compile
because its expecting two parameters. So is there another default constructor
that should be here? And when would you need to declare an iterator with
parameters?

Also, is it necessary to make a Vector object before declaring an iterator?

For example:
~~c
Vector<int> vec;
Vector<int>::iterator it;
~~~

Is it necessary to write that first line before the second line?

Sorry for so many questions. Im still quite confused.

**Answer:**
~~~c
int main() {
 Vector<double> foo( 7, 3.14 );

 Vector<double>::iterator bar( foo, 3 );
 // bar.parent == foo, .parent is a reference to foo
 // bar.i == 3

 ++bar; // bar.i == 4

 double gaz = * bar; // equivalent to: gaz = foo[4];  ... oops
}
~~~

A user-written class is a user-written class. It can have anything
(syntactically correct). It can be used in the ways that its interface allows.

This iterator must be constructed by giving it a Vector object and position.
No default construction. This ensures that every iterator points to a valid Vector.

The class definition would not have to be nested, but it is to emphasize that it
is part of the interface of the Vector. That these iterators are used with Vector objects.


The operator* is the dereference. It is logical that dereferencing an iterator
object returns (a reference) to the element of the Vector, which the iterator points to.

Finally, there is the oops. Your Vector does not have operator[]. The logically
closest thing that the Vector has is at().

This could be a genuine error on the teacher's part, or intentional to see
whether you catch and fix it.


Overall, this iterator is rather limited in functionality. Perhaps your task is to improve it?


PS. Your compiler should warn you a lot, when you instantiate methods of your Vector.

For example the at():

~~~c
T& at(int pos){
 if ( pos>0 && pos<size ) {
   return arr[pos];
 }
 else {
   // you have promised that this function returns a reference to
   // object that has type T, but what do you return on this branch?
   // NOTHING
 }
}
~~~

Calling your methods with invalid indices leads to undefined behaviour.

**Q:** Now this is what Im talking about. Your explanation is clear and concise. Thank you.

And yes, I was actually not done creating the Vector class: I have added the [] operator,
overloaded assignment, as well as throwing exceptions when invalid indices are passed.

Okay, one final thing.

I understand the example you gave of the bar iterator and passing it the vector as well as passing it an index = 3. But here is where im still a bit unclear about things. The way I have seen iterators declared is the following: `Vector<int>::iterator it;`

This creates an iterator for an int vector. This iterator works fine, I've used iterators like this before. But now my question is, what would the class implementation for THIS iterator look like? There are no parameters being passed here (unlike in my example in OP), so how exactly is this implemented?

Much appreciation.

**Answer:**
Member parent is a reference. Reference members must be initialized during construction.

The C++ Standard Library iterators are different. Many classes.
Compile-time polymorphism to enable generic algorithms.

http://www.cplusplus.com/reference/iterator/iterator/
http://www.cplusplus.com/reference/iterator/RandomAccessIterator/

Yes, you can default construct a STL iterator, but where does it point to? Nowhere. It is like an invalid pointer.
It should not be dereferenced or compared before it is set to point to a container.

How does one usually use a STL iterator?

~~~c
auto it = foo.begin();
if ( it != foo.end() ) {
 // ...
~~~

On line 1 I copy construct an iterator from iterator returned by foo.begin().
foo.begin() and foo.end() do create iterators that point to object foo.

I do not care whether they use iterator constructor that takes arguments or default construct and then set members. It is likely that an STL iterator holds a pointer.


STL iterators are flexible. You can reuse same iterator variable to point to different containers at different times. The feature may not yield much benefit, but at least it allows you to make catastrophic mistakes, just like with raw pointers.

Your `Vector<T>::iterator` is more strict. It automatically prohibits some error types.

It is a design philosophy question, whether to enforce syntactically The One Proper Use of your classes, or to allow much more leeway for the programmer.

#### Also helped: https://stackoverflow.com/questions/20966749/nested-iterator-class-begin-and-end-sentinel-issues

**Question:** I am having issues with my nested iterator class. The end() sentinel is returning 0, and I am very lost! Any help would be appreciated. I want this program to be able to take any type of input, e.g. an int, create the vector, and be able to fill the array until the end() sentinel has been reached, such as typing Q, or any non-integer. I took out a few lines of unnecessary code to shorten it.
~~~c
template <class T>
class Set
{
    private:
        vector<T> m_element;
        int size;
    public:
        Set() : size(0) {};
        ................
        ................
        ................

        class iterator;
        friend class iterator;
        class iterator
        {
            private:
                int i_index;
                Set& s;
            public:
                iterator(Set& is) :s(is), i_index(0) {}
                iterator(Set& is, bool) : s(is), i_index(s.size) {}
                int operator++()
                {
                    return s.m_element[++i_index];
                }
                (other postfix ++ operator)
                int current() const
                {
                    return s.m_element[i_index];
                }
                ....................
                bool operator!=(const iterator &rv) const
                {
                    return i_index != rv.i_index;
                }
                .............................
                int getI()
                {
                    return i_index;
                }
        };
        iterator begin() { return iterator(*this);}
        iterator end() {return iterator(*this, true);}
};

template <class T>
istream& operator>> (istream &in, Set<T> &element)
{
    T elementin;
    Set<T> is;
    class Set<T>::iterator it = element.begin();
    while(it != element.end())
    {
        in >> elementin;
        element.push(elementin);
    }
    return in;
}

int main()
{
    Set<int> intset;
    Set<int>::iterator it = intset.begin();
    for(int i = 0; i < 5; i++)
    {
        intset.push(i);
        cout << it.getI();
        ++it;
    }

    cout << endl << intset.begin() << intset.end();

    return 0;
}
~~~
OUTPUT:
01234
00

**Answer:**
~~~c
#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Set
{
  private:
    vector<T> m_element;
    int size;
  public:
    Set() : size(0) {};
    Set(const Set& rhs)
    {
       m_element = rhs.m_element;
       size = rhs.size;
    }

    void push(T data)
    {

      m_element.push_back(data);
      ++size;
    }

    class iterator;
    friend class iterator;
    class iterator
    {
      private:
        int i_index;
        Set& s;
      public:
        iterator(Set& is) :s(is), i_index(0) {}
        iterator(Set& is, bool) : s(is), i_index(s.size) {}
        iterator(Set& is, bool val,bool last) : s(is), i_index(s.size) {

          cout<<endl<<"size "<<s.size<<endl;
        if(last)
          i_index = s.size -1 ;
        }

        T operator*()
        {
          return s.m_element[i_index];
        }

        int operator++()
        {
          return s.m_element[++i_index];
        }
        int current() const
        {
          return s.m_element[i_index];
        }
        bool operator!=(const iterator &rv) const
        {
          return i_index != rv.i_index;
        }
        int getI()
        {
          return i_index;
        }
    };
    iterator begin() { return iterator(*this);}
//function to check if we have passed last element
        iterator end() {return iterator(*this, true);}
//function to get last element
        iterator last() {return iterator(*this, true,true);}

};

  template <class T>
istream& operator>> (istream &in, Set<T> &element)
{
  T elementin;
  Set<T> is;
  class Set<T>::iterator it = element.begin();
  while(it != element.end())
  {
    in >> elementin;
    element.push(elementin);
  }
  return in;
}

int main()
{
  Set<int> intset;
  Set<int>::iterator it = intset.begin();
  for(int i = 0; i < 5; i++)
  {
    intset.push(i);
    cout << it.getI();
    ++it;
  }

// cout << endl << intset.begin() << intset.end();
//We use last() to print the last element as end() confirms
//that we have passed last element and does not point to last element.
  cout << endl << *(intset.begin()) << " " <<*(intset.last())<<endl;

  return 0;
}
~~~

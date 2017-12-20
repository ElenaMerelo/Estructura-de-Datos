#### Multidimensional vector, how to

Q: Im trying to make use of a vector container to hold my matrix. But I dont know how to configure the vector container to be multidimensional. How does one configure the vector container to hold a multidimensional array data (matrix)?And how does one address element 2:3 of a 4x4 dimension vector?

A: You address it like this:
~~~cpp
// Create
vector< vector<int> > vec(4, vector<int>(4));
// Write
vec[2][3] = 10;
// Read
int a = vec[2][3];
~~~

Q: How about if you are going to dynamically add an element into your multidimensional vector? If my vector is one dimensional I do it this way:
~~~cpp
vector< int> mnumber;

for(unsigned i=0; i<10; i++)
     number.push_back(i+1);

number.clear();

for(unsigned i=0; i<30; i++)
     number.push_back(i+1);
~~~
But if its multidimensional? How do you do it?

A: Remember that a two dimentional vector is simply a vector of vectors. Each "subvector" or "row" is completely independant from the others, meaning that they can have different size. You can dynamically add elements to change the size of each row, and add elements to the main vector to add more rows.

You can simply use nested loops to build the structure. This is one way to do it:
~~~cpp
vector< vector<int> > vec;

for (int i = 0; i < 10; i++) {
    vector<int> row; // Create an empty row
    for (int j = 0; j < 20; j++) {
        row.push_back(i * j); // Add an element (column) to the row
    }
    vec.push_back(row); // Add the row to the main vector
}
~~~

It's not the only way, you may also add empty rows in one loop, and then use another loop that adds columns by inserting an element to all rows:
~~~cpp
vector< vector<int> > vec;

for (int i = 0; i < 10; i++) {
    vec.push_back(vector<int>()); // Add an empty row
}

for (int j = 0; j < 20; j++) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i].push_back(i * j); // Add column to all rows
    }

    // You could also use iterators:
    for (vector< vector<int> >::iterator it = vec.begin(); it != vec.end(); ++it) {
        it->push_back(j); // Add column to all rows
    }
}
~~~
There is also another possible way to use a vector as a two dimentional array. If each row will always have the same fixed length, you can use a single vector, and simulate two dimentions by calculating the index from a row and column number:
~~~cpp
const int rows = 10;
const int columns = 20;

vector<int> vec;
vec.resize(rows * columns);

for (int row = 0; row < rows; row++) {
    for (int col = 0; col < columns; col++) {
        vec[row * columns + col] = row * col;
    }
}
~~~

Q: How to create iterator/s for 2d vector (a vector of vectors)?
A: You need to use two iterators to traverse it, the first the iterator of the "rows", the second the iterators of the "columns" in that "row":
~~~cpp
//assuming you have a "2D" vector vvi (vector of vector of int's)
vector< vector<int> >::iterator row;
vector<int>::iterator col;
for (row = vvi.begin(); row != vvi.end(); row++) {
    for (col = row->begin(); col != row->end(); col++) {
        // do stuff ...
    }
}
~~~
From: http://www.cplusplus.com/forum/general/833/ and https://stackoverflow.com/questions/1784573/iterator-for-2d-vector

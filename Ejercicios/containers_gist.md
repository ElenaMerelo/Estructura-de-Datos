+ vector, deque and list all have constructors, destructor, operator=, begin, end, rbegin, rend, cbegin, cend, crbegin, crend, size, max_size, empty, resize, front, back, assign, emplace, insert, erase, emplace_back, push_back, pop_back, clear, swap and get_allocator.

+ vector, compared to deque and list, has capacity and reserve, and ,like deque, operator[], at and shrink_to_fit.

+ public member functions deque has and vector, list don´t: emplace_front, push_front, pop_front.

+ Forward lists are sequence containers that allow constant time insert and erase operations anywhere   within the sequence.

  They are implemented as singly-linked lists, which can store each of the elements they contain in different and unrelated storage locations. The ordering is kept by the association to each element of a link to the next element in the sequence.

  *The main design difference between a forward_list container and a list container is that the first keeps internally only a link to the next element, while the latter keeps two links per element: one pointing to the next element and one to the preceding one, allowing efficient iteration in both directions, but consuming additional storage per element and with a slight higher time overhead inserting and removing elements.* **forward_list objects are thus more efficient than list objects, although they can only be iterated forwards.**

  **Compared to** other base standard sequence containers (**array, vector and deque**), **forward_list perform generally better in inserting, extracting and moving elements in any position within the container**, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

  **The main drawback of forward_lists and lists compared to these other sequence containers is that they lack direct access to the elements by their position**. They also consume some extra memory to keep the linking information associated to each element (which may be an important factor for large lists of small-sized elements).

  Due to its nature as a linked list, having a size member that takes constant time would require it to keep an internal counter for its size (as list does). This would consume some extra storage and make insertion and removal operations slightly less efficient. To obtain the size of a forward_list object, you can use the distance algorithm with its begin and end, which is an operation that takes linear time.

+ set, multiset, map, multimap all have constructors, destructor, operator=, begin, end, rbegin, rend, cbegin, cend, crbegin, crend, empty, size, max_size, insert, erase, swap, clear, emplace, emplace_hint, find, count, lower_bound, upper_bound, equal_range, get_allocator.

+ Moreover, map has at and operator[], compared to the other associative containers.

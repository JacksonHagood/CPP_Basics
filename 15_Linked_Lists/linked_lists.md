# Linked Lists

Linked lists are a type of **abstract data type** that can store linear sequences of data. They are an alternative to using arrays with their own strengths and weaknesses. Linked lists are composed of nodes that store each data point as well as the memory address of the next node. The first node is denoted by a head pointer (with a tail pointer optionally pointing to the final node).

## Nodes

Nodes are objects in charge of two tasks: storing the data of the linked list and pointing to neighboring nodes. In a singly-linked list, nodes point only to the next node in the sequence. In a doubly linked list, nodes point to the next and previous nodes in the sequence. Note that the type of data nodes store can be different depending on the linked list's purpose (templates could also be used).

```C++
// singly linked list node
struct Node {
    char data; // data point of linked list
    Node* next; // pointer to next node in sequence
};
```

```C++
// doubly linked list node
struct Node {
    char data; // data point of linked list
    Node* next; // pointer to next node in sequence
    Node* prev; // pointer to previous node in sequence
};
```

Nodes are typically allocated on the heap as the programmer needs to manage when nodes are allocated and deallocated. For example, a node `A` could be declared on the heap and its data point set.

```C++
Node* A = new Node;
A->data = 'a';
```

As an example, if three singly-linked nodes (`A`, `B`, and `C`) were created, using their next pointers they could be placed in sequence as follows. Notice that the final node points to a `nullptr` as an indication that it is the final node.

```C++
A->next = B;
B->next = C;
C->next = nullptr;
```

## Linked Lists

Linked lists are collections of nodes on the heap. They reference these nodes using a head and (optionally) tail pointers. From these pointers, all of the nodes in the linked list can be found by traversing the previous node. As an example, a for loop can be used to traverse a linked list by starting at the head, iterating by moving a temporary pointer forward (`curr = curr->next`) and stopping once a `nullptr` is reached.

```C++
for (Node* curr = head; curr != nullptr; curr = curr->next) {
    cout << "Node: " << curr->data << '\n';
}
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./linked_lists.exe`
- cleanup: `make clean`

## References

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)

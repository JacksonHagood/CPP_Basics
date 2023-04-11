# include "../Appendix/helper.h"

struct Node {
    char data;
    Node* next;
};

int main() {
    outputHeading("Linked Lists");

    {
        // linked list is a collection of node objects located on the heap
        Node* A = new Node;
        A->data = 'a';

        Node* B = new Node;
        B->data = 'b';

        Node* C = new Node;
        C->data = 'c';

        // arrange nodes together
        A->next = B;
        B->next = C;
        C->next = nullptr;

        // head pointer points to first node
        Node* head = A;

        // iterate through linked list
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            cout << "Node: " << curr->data << '\n';
        }

        Node* curr = head;

        // nodes must be eventually deallocated to avoid memory leaks
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    promptInput();

    return 0;
}
typedef int (__cdecl *CompareFn)(void*, void*);
struct Node { Node* prev; Node* next; };
class Tree { public: Node* head; Node* FindNode(CompareFn compare, void* value); };
Node* Tree::FindNode(CompareFn compare, void* value) {
    Node* node = head;
    Node* sentinel = (Node*)((char*)this + 4);
    Node* result = sentinel;
    while (node != sentinel) {
        result = node;
        int cmp = compare(value, node);
        if (cmp < 0) node = node->prev;
        else if (cmp > 0) node = node->next;
        else return 0;
    }
    return result;
}

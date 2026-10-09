class Node { public: char pad[0x14]; Node* next; bool Contains(Node*); };
bool Node::Contains(Node* other) {
    Node* p = next;
    while (p) {
        if (p == other) return true;
        p = p->next;
    }
    return false;
}
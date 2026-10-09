struct Node {
    int pad;
    Node* next;
    void Link(Node* p);
};
void Node::Link(Node* p) {
    Node* cur = this;
    if (cur != p) {
        do {
            if (cur->next == 0) {
                cur->next = p;
                return;
            }
            cur = cur->next;
        } while (cur != p);
    }
}

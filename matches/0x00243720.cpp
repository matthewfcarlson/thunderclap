struct Node {
    Node* next;
    Node* child;
    Node* sibling;
};
Node* find(Node* root, Node* p) {
    Node* end = (Node*)((char*)root + 4);
    Node* q = p->child;
    if (q != end) {
        while (q->next != end)
            q = q->next;
    } else {
        q = p->sibling;
        while (q != end && p == q->child) {
            p = q;
            q = q->sibling;
        }
    }
    return q;
}
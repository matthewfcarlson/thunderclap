struct Node {
    char pad[16];
    int kind;
    Node* next;
    void target();
};
extern int a, b;
void __cdecl fun(Node*, int, void*, void*, int);
void Node::target() {
    if (kind == 3) {
        fun(this, 0, &a, &b, 0);
        return;
    }
    Node* q = next;
    while (q && q->kind != 3)
        q = q->next;
    fun(q, 0, &a, &b, 0);
}
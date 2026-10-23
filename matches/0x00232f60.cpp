class Node {
  public:
    int pad0[4];
    int type;
    Node* next;
    void* run();
};
extern void* FUN_00344e74(Node*, int, const void*, const void*, int);
extern const int DAT_0048e090;
extern const int DAT_004ca2b0;
void* Node::run() {
    if (type == 3)
        return FUN_00344e74(this, 0, &DAT_0048e090, &DAT_004ca2b0, 0);
    Node* q = next;
    while (q != 0 && q->type != 3)
        q = q->next;
    return FUN_00344e74(q, 0, &DAT_0048e090, &DAT_004ca2b0, 0);
}
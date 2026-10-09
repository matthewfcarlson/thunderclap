class Context {
  public:
    int Check();
};
class Node {
  public:
    char pad0[0x10];
    Context* mContext;
    char pad14[0x334 - 0x14];
    Node* mNext;
    void UpdateA(int, int);
    void UpdateB(int, int);
    void UpdateC(int, int);
    void UpdateNext(int, int);
};
void Node::UpdateA(int a, int b) {
    Node* p = this;
    do {
        if (p->mContext->Check()) {
            p->UpdateB(a, b);
            p->UpdateC(a, b);
        }
        if (!p->mNext)
            break;
        p->mNext->UpdateNext(a, b);
        p = p->mNext;
    } while (1);
}
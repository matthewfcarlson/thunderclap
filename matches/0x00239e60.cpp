// Same code shape as 0x00236f10 (propagated; names are from that function)
class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual void Call(void*);
    Node* next;
};
class Owner_239e60 {
  public:
    Node* head;
    void Walk(void*);
};
void Owner_239e60::Walk(void* arg) {
    for (Node* p = head; p; p = p->next)
        p->Call(arg);
}
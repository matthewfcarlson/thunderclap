class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual void Call(void*);
    Node* next;
};
class Owner_236f10 {
  public:
    Node* head;
    void Walk(void*);
};
void Owner_236f10::Walk(void* arg) {
    for (Node* p = head; p; p = p->next)
        p->Call(arg);
}
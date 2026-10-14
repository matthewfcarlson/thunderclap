class Node {
  public:
    virtual void f0();
    virtual void f1(void*);
    Node* next;
};
class Owner_236ee0 {
  public:
    Node* head;
    void run(void*);
};
void Owner_236ee0::run(void* arg) {
    for (Node* p = head; p != 0; p = p->next)
        p->f1(arg);
}
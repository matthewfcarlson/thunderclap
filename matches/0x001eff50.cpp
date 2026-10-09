class Node { public: virtual void Release(int); char pad[4]; Node* next; };
class Obj {
public:
    char pad[0x10];
    Node* head;
    void Flush();
    Obj* Dispose(unsigned char flag);
};
void destroy(Obj* o);

Obj* Obj::Dispose(unsigned char flag) {
    Node* n = head;
    while (n) {
        Node* cur = n;
        n = n->next;
        cur->Release(1);
    }
    Flush();
    if (flag & 1) destroy(this);
    return this;
}

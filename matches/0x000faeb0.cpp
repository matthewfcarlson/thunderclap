struct Node {
    char pad[4];
    Node* next;
    int count;
};
struct Obj {
    virtual void a();
    virtual __int64 b();   // returns 64 bits in edx:eax (callers 0x000f0590, 0x000f3270 push both)
};
extern int desc1, desc2;
extern Obj* __cdecl cast(Node*, int, void*, void*, int);
class Iter {
  public:
    char pad[8];
    Node* head;
    Node* current;
    char pad2[4];
    char done;
    __int64 Run();
};
__int64 Iter::Run() {
    Node* p = head;
    if (!p)
        return 0;
    Node* n;
    if (done == 1)
        n = 0;
    else {
        if (current == 0)
            n = p->next;
        else
            n = current->next;
        if (n && n->count < 2)
            n = 0;
    }
    current = n;
    if (!n)
        done = 1;
    return cast(n, 0, &desc1, &desc2, 0)->b();
}
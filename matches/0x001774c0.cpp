class Ref {
  public:
    virtual void A();
    virtual void Drop();
};
class Base {
  public:
    virtual void V();
    char pad[0x18];
    Base();
};
extern void* g_vft;
class Action : public Base {
  public:
    int a;
    Ref* b;
    int c;
    int d;
    int e;
    int f;
    Action(int, Ref*);
};
Action::Action(int x, Ref* p) {
    *(void**)this = &g_vft;
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (p)
        p->A();
    if (b)
        b->Drop();
    b = p;
}

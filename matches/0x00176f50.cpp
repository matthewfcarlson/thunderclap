class Thing {
  public:
    virtual void A();
    virtual void B();
};
extern char g_vftable[];
class Base {
  public:
    void* vptr;
    Base();
};
class RestPoseAction : public Base {
  public:
    char pad[0x18];
    int a;
    Thing* b;
    int c;
    RestPoseAction(int, Thing*);
};
RestPoseAction::RestPoseAction(int x, Thing* p) {
    vptr = g_vftable;
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    a = x;
    if (p)
        p->A();
    if (b)
        b->B();
    b = p;
}

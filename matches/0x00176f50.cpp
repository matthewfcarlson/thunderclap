class Thing_176f50 {
  public:
    virtual void A();
    virtual void B();
};
extern char g_vftable_176f50[];
class Base_176f50 {
  public:
    void* vptr;
    Base_176f50();
};
class RestPoseAction : public Base_176f50 {
  public:
    char pad[0x18];
    int a;
    Thing_176f50* b;
    int c;
    RestPoseAction(int, Thing_176f50*);
};
RestPoseAction::RestPoseAction(int x, Thing_176f50* p) {
    vptr = g_vftable_176f50;
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

class Ref_1774c0 {
  public:
    virtual void A();
    virtual void Drop();
};
class Action_1774c0 {
  public:
    virtual void V();
    char pad[0x18];
    Action_1774c0();
};
extern void* g_vft_1774c0;
class MomentumXZAddAction_1774c0 : public Action_1774c0 {
  public:
    int a;
    Ref_1774c0* b;
    int c;
    int d;
    int e;
    int f;
    MomentumXZAddAction_1774c0(int, Ref_1774c0*);
};
MomentumXZAddAction_1774c0::MomentumXZAddAction_1774c0(int x, Ref_1774c0* p) {
    *(void**)this = &g_vft_1774c0;
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

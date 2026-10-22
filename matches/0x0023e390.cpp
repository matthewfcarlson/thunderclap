extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23e390[];
void operator delete(void*);
class Ref_23e390 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23e390 {
  public:
    void* vptr;
    void Fin();
};
class WaitAction_23e390 : public Action_23e390 {
  public:
    char pad[28];
    Ref_23e390* m;
    WaitAction_23e390* f2(unsigned char flags);
};
WaitAction_23e390* WaitAction_23e390::f2(unsigned char flags) {
    vptr = g_vftable_23e390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

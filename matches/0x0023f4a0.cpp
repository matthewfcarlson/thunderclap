extern "C" void _ReadWriteBarrier();
extern void* g_vftable_23f4a0[];
void operator delete(void*);
class Ref_23f4a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23f4a0 {
  public:
    void* vptr;
    void Fin();
};
class BreakPointAction_23f4a0 : public Action_23f4a0 {
  public:
    char pad[0x1c];
    Ref_23f4a0* m;
    BreakPointAction_23f4a0* f2(unsigned char flags);
};
BreakPointAction_23f4a0* BreakPointAction_23f4a0::f2(unsigned char flags) {
    vptr = g_vftable_23f4a0;
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

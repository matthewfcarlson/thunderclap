extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1321d0[];
void operator delete(void*);
class Ref_1321d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1321d0 {
  public:
    void* vptr;
    void Fin();
};
class DebugPrintAction_1321d0 : public Action_1321d0 {
  public:
    char pad[28];
    Ref_1321d0* m;
    DebugPrintAction_1321d0* f2(unsigned char flags);
};
DebugPrintAction_1321d0* DebugPrintAction_1321d0::f2(unsigned char flags) {
    vptr = g_vftable_1321d0;
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

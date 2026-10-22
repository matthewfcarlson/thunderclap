extern "C" void _ReadWriteBarrier();
extern void* g_vftable_239150[];
void operator delete(void*);
class Ref_239150 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_239150 {
  public:
    void* vptr;
    void Fin();
};
class PrintAction_239150 : public Action_239150 {
  public:
    char pad[0x1c];
    Ref_239150* m;
    PrintAction_239150* f2(unsigned char flags);
};
PrintAction_239150* PrintAction_239150::f2(unsigned char flags) {
    vptr = g_vftable_239150;
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

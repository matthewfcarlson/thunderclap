extern "C" void _ReadWriteBarrier();
extern void* g_vftable_228b0[];
void operator delete(void*);
class Ref_228b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_228b0 {
  public:
    void* vptr;
    void Fin();
};
class CPropActorSetStateAction_228b0 : public CAction_228b0 {
  public:
    char pad[0x1c - 4];
    Ref_228b0* m;
    CPropActorSetStateAction_228b0* f2(unsigned char flags);
};
CPropActorSetStateAction_228b0* CPropActorSetStateAction_228b0::f2(unsigned char flags) {
    vptr = g_vftable_228b0;
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

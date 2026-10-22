extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10e950[];
extern void* g_vftable2[];
void operator delete(void*);
void operator delete[](void*);
class Ref_10e950 {
  public:
    virtual void F0();
    virtual void Release();
};
class Condition_10e950 {
  public:
    void* vptr;
    void Fin();
};

class HulkActionCountCondition_10e950 : public Condition_10e950 {
  public:
    char pad[0xc];
    void* m;
    HulkActionCountCondition_10e950* f2(unsigned char flags);
};
HulkActionCountCondition_10e950* HulkActionCountCondition_10e950::f2(unsigned char flags) {
    vptr = g_vftable_10e950;
    operator delete[](m);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

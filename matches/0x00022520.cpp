extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22520[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_22520 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_22520 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22520 : public Base_22520 {
  public:
    char pad[0x18];
    Ref_22520* m;
    Obj_22520* f2(unsigned char flags);
};
Obj_22520* Obj_22520::f2(unsigned char flags) {
    vptr = g_vftable_22520;
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

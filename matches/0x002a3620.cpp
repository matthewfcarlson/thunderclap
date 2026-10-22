extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a3620[];
void operator delete(void*);
class Ref_2a3620 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2a3620 {
  public:
    void* vptr;
    void Fin();
};
class DrawableHierarchy_2a3620 : public Entity_2a3620 {
  public:
    char pad[12];
    Ref_2a3620* m;
    DrawableHierarchy_2a3620* f2(unsigned char flags);
};
DrawableHierarchy_2a3620* DrawableHierarchy_2a3620::f2(unsigned char flags) {
    vptr = g_vftable_2a3620;
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

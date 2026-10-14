extern "C" void _ReadWriteBarrier();
extern void* g_vt_293890[];
void operator delete(void*);
class Ref_293890 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_293890 {
  public:
    void* vptr;
    void Fin();
};
class Obj_293890 : public Base_293890 {
  public:
    char pad[276 - 4];
    Ref_293890* m;
    Obj_293890* f2(unsigned char flags);
};
Obj_293890* Obj_293890::f2(unsigned char flags) {
    vptr = g_vt_293890;
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

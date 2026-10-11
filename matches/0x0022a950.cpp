extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern int g_count;
void operator delete(void*);
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    g_count--;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

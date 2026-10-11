extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042fcd4[];
extern void* g_base_vftable[];
void operator delete(void*);
void operator delete[](void*);
class Base {
  public:
    void* vptr;
};
class Obj : public Base {
  public:
    char pad[4];
    void* m8;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable_0042fcd4;
    _ReadWriteBarrier();
    if (m8)
        operator delete[](m8);
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}

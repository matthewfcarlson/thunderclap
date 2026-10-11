extern void* g_vftable[];
void operator delete(void*);
struct T1 {
    void Fini();
};
struct T2 {
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad4[0x14];
    T2 a18;
    char pad19[0x28 - 0x19];
    T1 a28;
    Obj* vfunc_5(unsigned char flags);
};
Obj* Obj::vfunc_5(unsigned char flags) {
    vptr = g_vftable;
    a28.Fini();
    a18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

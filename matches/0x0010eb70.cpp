extern void* g_vftable[];
void operator delete(void*);
class Sub {
  public:
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x14];
    Sub m18;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    m18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

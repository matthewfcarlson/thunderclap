extern void* g_vftable[];
void operator delete(void*);
struct Sub {
    char c;
    void Fin();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x18 - 4];
    Sub sub;
    Obj* f5(unsigned char flags);
};
Obj* Obj::f5(unsigned char flags) {
    vptr = g_vftable;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

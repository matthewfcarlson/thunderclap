extern void* g_vftable[];
void operator delete(void*);
void operator delete[](void*);
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x10 - 4];
    void* m10;
    Obj* f5(unsigned char flags);
};
Obj* Obj::f5(unsigned char flags) {
    void* p = m10;
    vptr = g_vftable;
    operator delete[](p);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

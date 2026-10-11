extern void* g_vA[];
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
    void* a = m10;
    vptr = g_vA;
    operator delete[](a);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

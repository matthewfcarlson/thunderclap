extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete(void*);
class Mem {
  public:
    ~Mem();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[28];
    Mem m;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;

    m.~Mem();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

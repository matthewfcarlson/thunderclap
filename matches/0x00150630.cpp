extern "C" void _ReadWriteBarrier();
extern void* g_vftable_150630[];
void operator delete(void*);
class Mem_150630 {
  public:
    ~Mem_150630();
};
class Base_150630 {
  public:
    void* vptr;
    void Fin();
};
class Obj_150630 : public Base_150630 {
  public:
    char pad[20];
    Mem_150630 m;
    Obj_150630* f2(unsigned char flags);
};
Obj_150630* Obj_150630::f2(unsigned char flags) {
    vptr = g_vftable_150630;

    m.~Mem_150630();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

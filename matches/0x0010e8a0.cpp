extern void* g_vftable_10e8a0[];
void operator delete(void*);
void operator delete[](void*);
class Base_10e8a0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_10e8a0 : public Base_10e8a0 {
  public:
    char pad[0x10 - 4];
    void* m10;
    Obj_10e8a0* f5(unsigned char flags);
};
Obj_10e8a0* Obj_10e8a0::f5(unsigned char flags) {
    void* p = m10;
    vptr = g_vftable_10e8a0;
    operator delete[](p);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern void* g_vA[];
void operator delete(void*);
void operator delete[](void*);
class Base_10e7c0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_10e7c0 : public Base_10e7c0 {
  public:
    char pad[0x10 - 4];
    void* m10;
    Obj_10e7c0* f5(unsigned char flags);
};
Obj_10e7c0* Obj_10e7c0::f5(unsigned char flags) {
    void* a = m10;
    vptr = g_vA;
    operator delete[](a);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

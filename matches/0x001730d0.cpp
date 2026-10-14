extern void* g_vftable_1730d0[];
void operator delete(void*);
struct Sub_1730d0 {
    char c;
    void Fin();
};
class Base_1730d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1730d0 : public Base_1730d0 {
  public:
    char pad[0x18 - 4];
    Sub_1730d0 sub;
    Obj_1730d0* f5(unsigned char flags);
};
Obj_1730d0* Obj_1730d0::f5(unsigned char flags) {
    vptr = g_vftable_1730d0;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern void* g_vftable_00427ff0[];
void operator delete(void*);
struct T1 {
    void Fini();
};
struct T2 {
    void Fini();
};
class Base_237430 {
  public:
    void* vptr;
    void Fin();
};
class Obj_237430 : public Base_237430 {
  public:
    char pad4[0x14];
    T2 a18;
    char pad19[0x28 - 0x19];
    T1 a28;
    Obj_237430* vfunc_5(unsigned char flags);
};
Obj_237430* Obj_237430::vfunc_5(unsigned char flags) {
    vptr = g_vftable_00427ff0;
    a28.Fini();
    a18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

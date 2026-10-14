extern void* g_vftable_1ab700[];
void operator delete(void*);
class Sub_1ab700 {
  public:
    void Fini();
};
class Base_1ab700 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1ab700 : public Base_1ab700 {
  public:
    char pad[0x14];
    Sub_1ab700 m18;
    Obj_1ab700* f2(unsigned char flags);
};
Obj_1ab700* Obj_1ab700::f2(unsigned char flags) {
    vptr = g_vftable_1ab700;
    m18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

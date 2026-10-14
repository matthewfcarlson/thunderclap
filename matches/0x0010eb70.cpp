extern void* g_vftable_10eb70[];
void operator delete(void*);
class Sub_10eb70 {
  public:
    void Fini();
};
class Base_10eb70 {
  public:
    void* vptr;
    void Fin();
};
class Obj_10eb70 : public Base_10eb70 {
  public:
    char pad[0x14];
    Sub_10eb70 m18;
    Obj_10eb70* f2(unsigned char flags);
};
Obj_10eb70* Obj_10eb70::f2(unsigned char flags) {
    vptr = g_vftable_10eb70;
    m18.Fini();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

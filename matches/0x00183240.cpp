extern void* g_vftable_183240[];
void operator delete(void*);
struct Sub_183240 {
    char c;
    void Fin();
};
class Base_183240 {
  public:
    void* vptr;
    void Fin();
};
class Obj_183240 : public Base_183240 {
  public:
    char pad[0x18 - 4];
    Sub_183240 sub;
    Obj_183240* f5(unsigned char flags);
};
Obj_183240* Obj_183240::f5(unsigned char flags) {
    vptr = g_vftable_183240;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern void* g_vftable_12fd40[];
void operator delete(void*);
void operator delete[](void*);
class Base_12fd40 {
  public:
    void* vptr;
    void Fin();
};
class Obj_12fd40 : public Base_12fd40 {
  public:
    char pad[0x10 - 4];
    void* m10;
    Obj_12fd40* f5(unsigned char flags);
};
Obj_12fd40* Obj_12fd40::f5(unsigned char flags) {
    void* p = m10;
    vptr = g_vftable_12fd40;
    operator delete[](p);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern void* g_vA[];
void operator delete(void*);
struct Sub_148360 {
    void* v;
    void Fin();
};
class Base_148360 {
  public:
    void* vptr;
    void Fin();
};
class Obj_148360 : public Base_148360 {
  public:
    char pad[0x18 - 4];
    Sub_148360 sub;
    Obj_148360* f5(unsigned char flags);
};
Obj_148360* Obj_148360::f5(unsigned char flags) {
    vptr = g_vA;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

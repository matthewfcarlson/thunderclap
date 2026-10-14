extern void* g_vA[];
void operator delete(void*);
struct Sub_124e00 {
    void* v;
    void Fin();
};
class Base_124e00 {
  public:
    void* vptr;
    void Fin();
};
class Obj_124e00 : public Base_124e00 {
  public:
    char pad[0x18 - 4];
    Sub_124e00 sub;
    Obj_124e00* f5(unsigned char flags);
};
Obj_124e00* Obj_124e00::f5(unsigned char flags) {
    vptr = g_vA;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}

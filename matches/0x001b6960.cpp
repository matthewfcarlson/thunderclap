typedef unsigned char byte;
extern int gVtable;
class Alloc {
  public:
    void f(void*, unsigned int);
};
extern Alloc gAlloc;
class CProjectile {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CProjectile* vfunc_2(byte);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
CProjectile* CProjectile::vfunc_2(byte param_2) {
    *(int*)this = (int)&gVtable;
    if ((param_2 & 1) != 0)
        gAlloc.f(this, 0x18);
    return this;
}
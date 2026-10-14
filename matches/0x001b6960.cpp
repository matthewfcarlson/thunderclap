typedef unsigned char byte_1b6960;
extern int gVtable_1b6960;
class Alloc_1b6960 {
  public:
    void f(void*, unsigned int);
};
extern Alloc_1b6960 gAlloc_1b6960;
class CProjectile {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CProjectile* vfunc_2(byte_1b6960);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
CProjectile* CProjectile::vfunc_2(byte_1b6960 param_2) {
    *(int*)this = (int)&gVtable_1b6960;
    if ((param_2 & 1) != 0)
        gAlloc_1b6960.f(this, 0x18);
    return this;
}
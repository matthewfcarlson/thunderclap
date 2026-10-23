extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
extern void* DAT_00491ca8;
extern void* DAT_004c24e8;
class Caster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c24e8, 0) != 0;
}
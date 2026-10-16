class Base {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class Caster : public Base {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* a;
extern void* b;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
extern "C" int __cdecl check(void*, void*, void*, void*, void*);
extern void* gA;
extern void* gB;
class Caster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool Caster::vfunc_0(void* p) {
    return check(p, 0, &gA, &gB, 0) != 0;
}
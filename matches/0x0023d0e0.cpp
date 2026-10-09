typedef unsigned int u32;
struct NotCondition { virtual void a(); virtual void b(); virtual void c(); };
extern void* __cdecl FUN_0008d690(unsigned int);
struct Helper { void f(int); };
class ConditionFactoryTemplate { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual NotCondition* vfunc_5(); };
NotCondition* ConditionFactoryTemplate::vfunc_5() {
    NotCondition* p = (NotCondition*)FUN_0008d690(0xc);
    if (p) {
        ((Helper*)p)->f(2);
        *(u32*)p = 0x428a24;
        return p;
    }
    return (NotCondition*)0;
}
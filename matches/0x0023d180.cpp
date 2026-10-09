typedef unsigned int u32;
extern void* __cdecl FUN_0008d690(unsigned int);
struct Init { void init(int); };
class ConditionFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* vfunc_5(); };
void* ConditionFactoryTemplate::vfunc_5() {
    Init* p = (Init*)FUN_0008d690(12);
    if (p) {
        p->init(1);
        *(u32*)p = 0x00428a44;
        return p;
    }
    return 0;
}
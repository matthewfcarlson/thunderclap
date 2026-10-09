typedef unsigned int uint;
void* __cdecl Alloc(uint);
struct Base { void Init(int); };
struct Sub { void Setup(); };
class ConditionFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* vfunc_5(); };
void* ConditionFactoryTemplate::vfunc_5() {
    Base* p = (Base*)Alloc(0x20);
    if (p) {
        p->Init(0);
        *(uint*)p = 0x41916c;
        ((uint*)p)[3] = 0xffffffff;
        ((uint*)p)[4] = 0;
        ((Sub*)((char*)p + 0x18))->Setup();
        return p;
    }
    return (void*)0;
}
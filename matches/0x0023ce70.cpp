typedef unsigned char u8;
typedef unsigned int u32;
extern "C" void* __cdecl Alloc(unsigned int);
extern u32 PlatformVtable;
class PlatformCondition { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); char pad[8]; void init(int); u8 flags[4]; };
class Factory { public: void* vfunc_5(); };
void* Factory::vfunc_5() {
    PlatformCondition* p = (PlatformCondition*)Alloc(0x10);
    if (p != 0) {
        p->init(0);
        p->flags[0] = 1; p->flags[1] = 1; p->flags[2] = 1; p->flags[3] = 1;
        *(u32*)p = (u32)&PlatformVtable;
        return p;
    }
    return 0;
}
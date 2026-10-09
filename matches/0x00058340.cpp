struct CLuaNumberCondition { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); void init(int); };
extern void* __cdecl Allocate(unsigned int);
struct ConditionFactoryTemplate { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); void* vfunc_5(); };
void* ConditionFactoryTemplate::vfunc_5() {
    CLuaNumberCondition* p = (CLuaNumberCondition*)Allocate(0x54);
    if (p) {
        p->init(0);
        *(unsigned int*)p = 0x3f7304;
        *(unsigned int*)((char*)p + 0xc) = 2;
        *(unsigned int*)((char*)p + 0x50) = 0;
        *((unsigned char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}
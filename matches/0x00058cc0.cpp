extern "C" void* __cdecl Alloc(unsigned int);
struct Obj { void Init(int); };
struct Sub { void Init(); };
struct CCharacterTemplateCondition { char pad[24]; };
struct Factory { void* vfunc_5(); };
void* Factory::vfunc_5() {
    CCharacterTemplateCondition* p = (CCharacterTemplateCondition*)Alloc(0x18);
    if (p) {
        ((Obj*)p)->Init(0);
        *(unsigned int*)p = 0x3f7328;
        *(unsigned int*)((char*)p + 0xc) = 0;
        ((Sub*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}
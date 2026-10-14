extern "C" char DAT_003f7328[];
extern "C" void* __cdecl Alloc(unsigned int);
struct Obj_58cc0 {
    void Init(int);
};
struct Sub_58cc0 {
    void Init();
};
struct CCharacterTemplateCondition {
    char pad[24];
};
struct Factory_58cc0 {
    void* vfunc_5();
};
void* Factory_58cc0::vfunc_5() {
    CCharacterTemplateCondition* p = (CCharacterTemplateCondition*)Alloc(0x18);
    if (p) {
        ((Obj_58cc0*)p)->Init(0);
        *(unsigned int*)p = ((int)DAT_003f7328);
        *(unsigned int*)((char*)p + 0xc) = 0;
        ((Sub_58cc0*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}
extern "C" char DAT_00416a88[];
extern "C" int gCount_16afa0 = 0;
extern "C" void* gSlot_16afa0 = 0;
extern const char gName_16afa0[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Init_16afa0 {
    void InitName(const char*);
};
extern "C" void __cdecl FUN_002347b0(void**, void**, int);
struct Param {
    void* vptr;
    char pad4[12];
    void* field10;
};
void FUN_0016afa0() {
    void* local;
    if (gCount_16afa0 != 0) {
        ++gCount_16afa0;
        return;
    }
    Param* p = (Param*)FUN_0008d690(0x18);
    if (p) {
        ((Init_16afa0*)p)->InitName(gName_16afa0);
        p->vptr = (void*)((int)DAT_00416a88);
        p->field10 = (void*)0x1653d0;
        local = p;
    } else
        local = 0;
    FUN_002347b0((void**)&gSlot_16afa0, &local, 1);
    ++gCount_16afa0;
}
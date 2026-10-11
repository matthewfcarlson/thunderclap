extern "C" char DAT_00416a88[];
extern "C" int gCount = 0;
extern "C" void* gSlot = 0;
extern const char gName[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Init {
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
    if (gCount != 0) {
        ++gCount;
        return;
    }
    Param* p = (Param*)FUN_0008d690(0x18);
    if (p) {
        ((Init*)p)->InitName(gName);
        p->vptr = (void*)((int)DAT_00416a88);
        p->field10 = (void*)0x1653d0;
        local = p;
    } else
        local = 0;
    FUN_002347b0((void**)&gSlot, &local, 1);
    ++gCount;
}
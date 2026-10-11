extern "C" void __cdecl FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern "C" const void* loc_vftable;

class LocationCondition {
  public:
    char pad0[0x10];
    void* m1;       // +0x10
    char pad2[4];   // +0x14
    void* m2;       // +0x18
    void Cleanup(); // FUN_002345b0, thiscall no args
    LocationCondition* vfunc_5(int b);
};

LocationCondition* LocationCondition::vfunc_5(int b) {
    void* p1 = m1;
    *(const void**)this = &loc_vftable;
    FUN_00267090(p1);
    FUN_00267090(m2);
    Cleanup();
    if (b & 1) {
        operator delete(this);
    }
    return this;
}

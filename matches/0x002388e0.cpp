// Same code shape as 0x0012e590 (propagated; names are from that function)
typedef unsigned int u32;
void thunk_FUN_00267090(u32);
extern int DebugPrintCondition_vftable;
struct Base {
    void finish();
};
struct DebugPrintCondition : Base {
    void* vt;
    char pad4[8];
    u32 a;
    u32 b;
    void dtorish();
};
void DebugPrintCondition::dtorish() {
    u32 x = a;
    vt = &DebugPrintCondition_vftable;
    thunk_FUN_00267090(x);
    thunk_FUN_00267090(b);
    Base::finish();
}

// Same code shape as 0x0012e590 (propagated; names are from that function)
typedef unsigned int u32_2388e0;
void thunk_FUN_00267090(u32_2388e0);
extern int DebugPrintCondition_vftable;
struct Base_2388e0 {
    void finish();
};
struct DebugPrintCondition : Base_2388e0 {
    void* vt;
    char pad4[8];
    u32_2388e0 a;
    u32_2388e0 b;
    void dtorish();
};
void DebugPrintCondition::dtorish() {
    u32_2388e0 x = a;
    vt = &DebugPrintCondition_vftable;
    thunk_FUN_00267090(x);
    thunk_FUN_00267090(b);
    Base_2388e0::finish();
}

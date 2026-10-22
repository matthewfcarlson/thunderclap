typedef unsigned int u32_12e590;
void thunk_FUN_00267090(u32_12e590);
extern int DebugPrintCondition_vftable;
struct Condition_12e590 {
    void finish();
};
struct DebugPrintCondition : Condition_12e590 {
    void* vt;
    char pad4[8];
    u32_12e590 a;
    u32_12e590 b;
    void dtorish();
};
void DebugPrintCondition::dtorish() {
    u32_12e590 x = a;
    vt = &DebugPrintCondition_vftable;
    thunk_FUN_00267090(x);
    thunk_FUN_00267090(b);
    Condition_12e590::finish();
}

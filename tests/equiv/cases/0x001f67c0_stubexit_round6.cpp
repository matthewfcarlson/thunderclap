// FUN_001f67c0 @ 0x001f67c0
// (integ4, stubexit; rev5) must fail with the rule, and not without it: an extra call on the sixth round only. Random draws almost never leave the loop after six rounds and the loop repair ends it at once; the rule's drawn rounds reach it
int FUN_00247930(int a, int b);
void FUN_00247a90(int a, int b, int c);
extern "C++" void thunk_FUN_00270a50();
void FUN_002656a0();
extern "C" void FUN_00240bb0();
struct Obj_1f67c0 {
    void FUN_001f67c0();
    void Step(float f);
    int pad0;
    int mA;
    char pad[0x10];
    int mB;
    char mFlag;
};
void Obj_1f67c0::FUN_001f67c0() {
    if (!mB)
        return;
    if (FUN_00247930(mA, mB) == 1) {
        int k = 0;
        while (FUN_00247930(mA, mB) != 2) {
            thunk_FUN_00270a50();
            FUN_002656a0();
            FUN_00240bb0();
            Step(0.001f);
            if (++k == 6)
                FUN_00240bb0();
        }
    }
    if (FUN_00247930(mA, mB) == 2) {
        FUN_00247a90(mA, mB, 0);
        return;
    }
    mFlag = 1;
}

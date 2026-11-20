// FUN_001f67c0 @ 0x001f67c0
// (integ4, stubexit; rev5) a wait loop (`while (Status(v, s) != 2)`) whose stub result almost never ends it at random (2 of the draws): with EQUIV_OFF=stubexit the inputs that enter it time out and its edges stay uncovered; with the rule they are compared
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
        while (FUN_00247930(mA, mB) != 2) {
            thunk_FUN_00270a50();
            FUN_002656a0();
            FUN_00240bb0();
            Step(0.001f);
        }
    }
    if (FUN_00247930(mA, mB) == 2) {
        FUN_00247a90(mA, mB, 0);
        return;
    }
    mFlag = 1;
}

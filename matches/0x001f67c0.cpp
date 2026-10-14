int FUN_00247930(int a, int b);
void FUN_00247a90(int a, int b, int c);
void thunk_FUN_00270a50();
void FUN_002656a0();
void FUN_00240bb0();

class Obj_1f67c0 {
  public:
    void Run();
    void Step(float f);
    int pad0;
    int mA;
    char pad[0x10];
    int mB;
    char mFlag;
};

void Obj_1f67c0::Run() {
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

struct CAxisTimeCondition {
    void *vtable;
    int pad0[2];
    int fieldC;
    int field10;
    int field14;
    CAxisTimeCondition();
};
extern void __stdcall Init(int);
CAxisTimeCondition::CAxisTimeCondition() {
    Init(0);
    fieldC = 0;
    vtable = (void *)0x3f6e4c;
    field10 = 4;
    field14 = 0;
}
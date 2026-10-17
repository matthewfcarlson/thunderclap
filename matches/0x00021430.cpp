struct Ref {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
};
struct CActionBase {
    CActionBase();
    virtual void FUN_00000002();
    char pad[0x18];
    Ref* ref;
};
struct CAction : CActionBase {
    virtual void FUN_00000003();
};
struct CHeliDeathSpiralAction : CAction {
    int value;
    int state;
    int fields[7];
    CHeliDeathSpiralAction(int value, Ref* ref);
    virtual void FUN_00000004();
};
extern void* DAT_003f3390[];
extern void* DAT_003f3de0[];
CHeliDeathSpiralAction::CHeliDeathSpiralAction(int v, Ref* r) : CAction() {
    *(void***)this = DAT_003f3390;
    this->ref = 0;
    if (r)
        r->FUN_00000000();
    if (this->ref)
        this->ref->FUN_00000001();
    this->ref = r;
    state = 0;
    *(void***)this = DAT_003f3de0;
    for (int i = 0; i < 7; ++i)
        fields[i] = 0;
    value = v;
}

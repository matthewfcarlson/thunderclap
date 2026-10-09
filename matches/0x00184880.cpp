class Ref {
  public:
    virtual void Fn();
    virtual void Release();
};
extern void BaseInit();
extern int vtable;
class BallAndChainShootAction {
  public:
    BallAndChainShootAction(int, Ref*);
    int vt;
    char pad04[0x18];
    int mA;
    Ref* mRef;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
};
BallAndChainShootAction::BallAndChainShootAction(int a, Ref* b) {
    BaseInit();
    vt = (int)&vtable;
    int* q = &mA;
    *q = 0;
    mRef = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = (int)0xbf800000;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    mA = a;
    if (b)
        b->Fn();
    if (mRef)
        mRef->Release();
    mRef = b;
}
// Same code shape as 0x0001cfd0 (propagated; names are from that function)
class Ref_1d020 {
  public:
    virtual void A();
    virtual void B();
};
extern void BaseInit();
extern int ActionVtable;
extern int HitVtable;
class Hit_1d020 {
  public:
    int* vptr;
    char pad[0x18];
    Ref_1d020* mRef;
    int mValue;
    int mZero;
    Hit_1d020(int a, Ref_1d020* b);
};
Hit_1d020::Hit_1d020(int a, Ref_1d020* b) {
    BaseInit();
    vptr = &ActionVtable;
    mRef = 0;
    if (b)
        b->A();
    if (mRef)
        mRef->B();
    mRef = b;
    mValue = a;
    mZero = 0;
    vptr = &HitVtable;
}

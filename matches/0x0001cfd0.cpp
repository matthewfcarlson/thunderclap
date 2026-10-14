class Ref_1cfd0 {
  public:
    virtual void A();
    virtual void B();
};
extern void BaseInit();
extern int ActionVtable;
extern int HitVtable;
class Hit_1cfd0 {
  public:
    int* vptr;
    char pad[0x18];
    Ref_1cfd0* mRef;
    int mValue;
    int mZero;
    Hit_1cfd0(int a, Ref_1cfd0* b);
};
Hit_1cfd0::Hit_1cfd0(int a, Ref_1cfd0* b) {
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

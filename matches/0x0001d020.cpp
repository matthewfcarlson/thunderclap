// Same code shape as 0x0001cfd0 (propagated; names are from that function)
class Ref_1d020 {
  public:
    virtual void A();
    virtual void B();
};
struct Ctor_00232660 {
    Ctor_00232660();
};
extern int ActionVtable;
extern int HitVtable;
class Hit_1d020 : public Ctor_00232660 {
  public:
    int* vptr;
    char pad[0x18];
    Ref_1d020* mRef;
    int mValue;
    int mZero;
    Hit_1d020(int a, Ref_1d020* b);
};
Hit_1d020::Hit_1d020(int a, Ref_1d020* b) : Ctor_00232660() {
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

class Ref_1cfd0 {
  public:
    virtual void A();
    virtual void B();
};
struct Ctor_00232660 {
    Ctor_00232660();
};
extern int ActionVtable;
extern int HitVtable;
class Hit_1cfd0 : public Ctor_00232660 {
  public:
    int* vptr;
    char pad[0x18];
    Ref_1cfd0* mRef;
    int mValue;
    int mZero;
    Hit_1cfd0(int a, Ref_1cfd0* b);
};
Hit_1cfd0::Hit_1cfd0(int a, Ref_1cfd0* b) : Ctor_00232660() {
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

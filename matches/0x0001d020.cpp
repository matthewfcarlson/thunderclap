// Same code shape as 0x0001cfd0 (propagated; names are from that function)
class Ref { public: virtual void A(); virtual void B(); };
extern void BaseInit();
extern int ActionVtable;
extern int HitVtable;
class Hit { public: int *vptr; char pad[0x18]; Ref *mRef; int mValue; int mZero; Hit(int a, Ref *b); };
Hit::Hit(int a, Ref *b) {
    BaseInit();
    vptr = &ActionVtable;
    mRef = 0;
    if (b) b->A();
    if (mRef) mRef->B();
    mRef = b;
    mValue = a;
    mZero = 0;
    vptr = &HitVtable;
}

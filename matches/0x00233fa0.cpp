class Obj_233fa0 {
  public:
    virtual void A();
    virtual void B();
};
void FUN_00267090(int);
class Holder_233fa0 {
  public:
    Obj_233fa0* mObj;
    int mValue;
    bool Set(int dummy, Obj_233fa0* p);
};
bool Holder_233fa0::Set(int dummy, Obj_233fa0* p) {
    if (p != mObj) {
        FUN_00267090(mValue);
        mValue = 0;
        if (p)
            p->A();
        if (mObj)
            mObj->B();
        mObj = p;
    }
    return true;
}
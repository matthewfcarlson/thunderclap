class Obj {
  public:
    virtual void A();
    virtual void B();
};
void FUN_00267090(int);
class Holder {
  public:
    Obj* mObj;
    int mValue;
    bool Set(int dummy, Obj* p);
};
bool Holder::Set(int dummy, Obj* p) {
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
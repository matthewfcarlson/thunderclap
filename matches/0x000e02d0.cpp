class Obj_e02d0;
typedef void (Obj_e02d0::*MFn_e02d0)(int, int, int, int);
class Obj_e02d0 {
  public:
    void Dummy();
};
class ParseFunctor {
  public:
    virtual void vfunc_0(int, int);
    Obj_e02d0* mObj;
    MFn_e02d0 mFn;
    int mC;
    int mD;
};
void ParseFunctor::vfunc_0(int a, int b) {
    MFn_e02d0 fn = mFn;
    (mObj->*fn)(a, mC, mD, b);
}

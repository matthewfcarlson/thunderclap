class Obj;
typedef void (Obj::*MFn)(int, int, int, int);
class Obj { public: void Dummy(); };
class ParseFunctor {
public:
    virtual void vfunc_0(int, int);
    Obj* mObj;
    MFn mFn;
    int mC;
    int mD;
};
void ParseFunctor::vfunc_0(int a, int b) {
    MFn fn = mFn;
    (mObj->*fn)(a, mC, mD, b);
}

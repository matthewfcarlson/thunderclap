extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3438[];
class Ref_190a0 {
  public:
    virtual void Add();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    char pad[24];
    Ref_190a0* mRef;
    int x;
};
class CDropAction : public CAction {
  public:
    virtual void D0();
    virtual void D1();
    Ref_190a0* mOther;
    int a;
    int b;
    CDropAction(int, Ref_190a0*);
};
CDropAction::CDropAction(int v, Ref_190a0* r) : CAction() {
    *(int*)this = ((int)DAT_003f3390);
    mRef = 0;
    if (r)
        r->Add();
    if (mRef)
        mRef->Release();
    mRef = r;
    x = v;
    *(int*)this = ((int)DAT_003f3438);
    mOther = 0;
    b = 0;
}

extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3d30[];
class Ref {
  public:
    virtual void F();
    virtual void G();
};
class CAction {
  public:
    CAction();
    virtual void F();
    virtual void G();
    char pad[0x1c - 4];
    Ref* mRef;
    int mValue;
    int mOther;
};
class CSnapToWallAction : public CAction {
  public:
    CSnapToWallAction(int, Ref*);
    virtual void F();
    virtual void G();
};
CSnapToWallAction::CSnapToWallAction(int v, Ref* r) {
    int* p = (int*)this;
    *p = ((int)DAT_003f3390);
    mRef = 0;
    if (r)
        r->F();
    if (mRef)
        mRef->G();
    mRef = r;
    mValue = v;
    p[0] = ((int)DAT_003f3d30);
    mOther = 0;
}

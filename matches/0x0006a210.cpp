class Base {
  public:
    virtual void FnBase0();
    virtual void FnBase1();
    Base();
};

class CIntangibleToActorsTrack : public Base {
  public:
    virtual void Fn0();
    virtual void Fn1();
    CIntangibleToActorsTrack();

  private:
    char pad0[4];
    int mCount;
    float mFloat0;
    float mFloat1;
};

CIntangibleToActorsTrack::CIntangibleToActorsTrack() {
    mFloat0 = 0.0f;
    mFloat1 = -1.0f;
    mCount = 1;
}

class Sub {
  public:
    virtual void A();
    virtual void B();
};

class Obj {
  public:
    char pad[0xc];
    Sub mSub;
    char pad2[0x30];
    int mVal;
    void Set(int v);
};

void Obj::Set(int v) {
    mSub.A();
    mVal = v;
    mSub.B();
}

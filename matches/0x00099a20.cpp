class Sub {
  public:
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void A4();
    virtual void A5();
    virtual void A6();
    virtual void A7();
    virtual void A8();
    virtual void Vfunc9();
};

class Owner {
  public:
    char pad[0xc4];
    Sub* mSub;
    void Target();
};

void Owner::Target() {
    mSub->Vfunc9();
}

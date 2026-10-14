class Thing_2730c0 {
  public:
    virtual void A();
    virtual void B();
};
class Target_2730c0 {
    char pad[0x0c];
    Thing_2730c0 mThing;
    char pad2[0x7c];
    int mValue;

  public:
    bool F();
};
bool Target_2730c0::F() {
    mThing.A();
    bool r = mValue != 0;
    mThing.B();
    return r;
}
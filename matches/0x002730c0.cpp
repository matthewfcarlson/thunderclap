class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Target {
    char pad[0x0c];
    Thing mThing;
    char pad2[0x7c];
    int mValue;

  public:
    bool F();
};
bool Target::F() {
    mThing.A();
    bool r = mValue != 0;
    mThing.B();
    return r;
}
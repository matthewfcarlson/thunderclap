class Thing_e9100 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_e9100 {
  public:
    char pad[0x60];
    Thing_e9100* mThing;
    void Set(Thing_e9100* p);
};
void Owner_e9100::Set(Thing_e9100* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}
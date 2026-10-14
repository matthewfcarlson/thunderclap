// Same code shape as 0x000e9100 (propagated; names are from that function)
class Thing_2e01a0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2e01a0 {
  public:
    char pad[0x60];
    Thing_2e01a0* mThing;
    void Set(Thing_2e01a0* p);
};
void Owner_2e01a0::Set(Thing_2e01a0* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}
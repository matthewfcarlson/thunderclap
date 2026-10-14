// Same code shape as 0x000e9100 (propagated; names are from that function)
class Thing_2b7c80 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2b7c80 {
  public:
    char pad[0x60];
    Thing_2b7c80* mThing;
    void Set(Thing_2b7c80* p);
};
void Owner_2b7c80::Set(Thing_2b7c80* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}
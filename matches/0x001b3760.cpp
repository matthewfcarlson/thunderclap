class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0x30];
    Thing* mThing;
    void Set(Thing*);
};
void Owner::Set(Thing* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}
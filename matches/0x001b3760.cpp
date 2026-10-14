class Thing_1b3760 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1b3760 {
  public:
    char pad[0x30];
    Thing_1b3760* mThing;
    void Set(Thing_1b3760*);
};
void Owner_1b3760::Set(Thing_1b3760* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}
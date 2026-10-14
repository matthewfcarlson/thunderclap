class Thing_310e90 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_310e90 {
    char pad[0x220];
    Thing_310e90* member;

  public:
    void Set(Thing_310e90* p);
};
void Owner_310e90::Set(Thing_310e90* p) {
    if (p)
        p->A();
    if (member)
        member->B();
    member = p;
}

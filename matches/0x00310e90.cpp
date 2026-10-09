class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
    char pad[0x220];
    Thing* member;

  public:
    void Set(Thing* p);
};
void Owner::Set(Thing* p) {
    if (p)
        p->A();
    if (member)
        member->B();
    member = p;
}

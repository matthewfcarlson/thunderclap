class Thing {
  public:
    virtual void First();
    virtual void Second();
};
class Owner {
  public:
    char pad[0x40];
    Thing* member;
    void Set(Thing* p);
};
void Owner::Set(Thing* p) {
    member->Second();
    member = p;
    p->First();
}
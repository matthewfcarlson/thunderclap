class Thing_29b300 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_29b300 {
  public:
    char pad[0x40];
    Thing_29b300* member;
    void Set(Thing_29b300* p);
};
void Owner_29b300::Set(Thing_29b300* p) {
    member->Second();
    member = p;
    p->First();
}
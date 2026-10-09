class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0xc];
    Ref* member;
    void clear();
};
void Owner::clear() {
    if (member) {
        member->B();
        member = 0;
    }
}
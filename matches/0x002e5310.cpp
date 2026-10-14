class Ref_2e5310 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2e5310 {
  public:
    char pad[0xc];
    Ref_2e5310* member;
    void clear();
};
void Owner_2e5310::clear() {
    if (member) {
        member->B();
        member = 0;
    }
}
class Inner {
  public:
    void A();
    void B(int);
};
class Obj {
    char pad[0x88];
    Inner* member;

  public:
    void Target(int);
};
void Obj::Target(int x) {
    if (member) {
        member->A();
        member->B(x);
    }
}
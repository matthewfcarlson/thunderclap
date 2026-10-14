class Inner_caee0 {
  public:
    void A();
    void B(int);
};
class Obj_caee0 {
    char pad[0x88];
    Inner_caee0* member;

  public:
    void Target(int);
};
void Obj_caee0::Target(int x) {
    if (member) {
        member->A();
        member->B(x);
    }
}
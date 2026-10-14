class B_b3d40 {
  public:
    void call(int);
};
class A_b3d40 {
  public:
    int pad;
    B_b3d40* member;
    void target();
};
void A_b3d40::target() {
    member->call(1);
}
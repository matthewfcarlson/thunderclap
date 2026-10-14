class B_ae930 {
  public:
    void F(int);
};
class A_ae930 {
  public:
    char pad[4];
    B_ae930* p4;
    int p8;
    void Set(int x);
};
void A_ae930::Set(int x) {
    if (p4) {
        p4->F(x);
        p8 = x;
    } else {
        p8 = x;
    }
}
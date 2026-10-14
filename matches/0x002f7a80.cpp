class B_2f7a80 {
  public:
    virtual void F();
};
class A_2f7a80 {
  public:
    int pad;
    B_2f7a80* p;
    void Set(B_2f7a80* b);
};
void A_2f7a80::Set(B_2f7a80* b) {
    p = b;
    b->F();
}
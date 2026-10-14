class B_f8b90 {
  public:
    virtual void V(int);
};
class A_f8b90 {
  public:
    virtual void Finish();
    char pad[0x3c];
    int value;
    char pad2[4];
    B_f8b90* b;
    void Set(int);
};
void A_f8b90::Set(int x) {
    value = x;
    if (b)
        b->V(x);
    Finish();
}
class A {
  public:
    char p[0x90];
    int mRef;
    void Set(int v);
};
void A::Set(int v) {
    mRef = v;
}

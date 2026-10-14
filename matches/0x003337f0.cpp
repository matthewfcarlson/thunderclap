class A {
  public:
    char pad[0x6c];
    int m6c;
    void Helper();
    void Set(int x);
};
void A::Set(int x) {
    m6c = x;
    Helper();
}

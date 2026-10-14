class A {
  public:
    char pad[0x64];
    int m64;
    void Set(int arg);
    void Sub();
};

void A::Set(int arg) {
    m64 = arg;
    Sub();
}

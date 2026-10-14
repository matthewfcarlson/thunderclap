class A_333800 {
  public:
    char pad[0x64];
    int m64;
    void Set(int arg);
    void Sub();
};

void A_333800::Set(int arg) {
    m64 = arg;
    Sub();
}

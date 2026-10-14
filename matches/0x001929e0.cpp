class X_1929e0 {
  public:
    char pad[0x60];
    unsigned char m;
    bool Set(unsigned char v);
};

bool X_1929e0::Set(unsigned char v) {
    m = v;
    return true;
}

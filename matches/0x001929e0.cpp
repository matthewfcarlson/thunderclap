class X {
  public:
    char pad[0x60];
    unsigned char m;
    bool Set(unsigned char v);
};

bool X::Set(unsigned char v) {
    m = v;
    return true;
}

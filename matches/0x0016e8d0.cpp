class C_16e8d0 {
  public:
    char pad[0x4c];
    unsigned char m4c;
    bool Set(unsigned char v);
};
bool C_16e8d0::Set(unsigned char v) {
    m4c = v;
    return true;
}
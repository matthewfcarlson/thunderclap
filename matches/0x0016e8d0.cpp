class C {
  public:
    char pad[0x4c];
    unsigned char m4c;
    bool Set(unsigned char v);
};
bool C::Set(unsigned char v) {
    m4c = v;
    return true;
}
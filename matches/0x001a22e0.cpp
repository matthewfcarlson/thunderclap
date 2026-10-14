class C {
  public:
    char pad[0x50];
    unsigned char m50;
    bool SetX(unsigned char x);
};

bool C::SetX(unsigned char x) {
    m50 = x;
    return true;
}
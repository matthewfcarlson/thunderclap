class C_1a22e0 {
  public:
    char pad[0x50];
    unsigned char m50;
    bool SetX(unsigned char x);
};

bool C_1a22e0::SetX(unsigned char x) {
    m50 = x;
    return true;
}
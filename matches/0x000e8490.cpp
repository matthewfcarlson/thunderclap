class T {
  public:
    void Set(unsigned char x);
    char pad[0x2074];
    unsigned char mX;
};

void T::Set(unsigned char x) {
    mX = x;
}

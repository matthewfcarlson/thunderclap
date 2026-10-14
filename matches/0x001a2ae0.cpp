class X {
  public:
    char pad[0x148];
    char m148;
    char f4(unsigned char v);
};

char X::f4(unsigned char v) {
    m148 = (char)v;
    return 1;
}

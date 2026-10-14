class Obj {
  public:
    char m0[0xfc];
    char m1;
    unsigned char Set(unsigned char v);
};

unsigned char Obj::Set(unsigned char v) {
    m1 = v;
    return 1;
}

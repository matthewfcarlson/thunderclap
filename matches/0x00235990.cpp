class Obj {
  public:
    char pad[0x1c];
    char m1c;
    unsigned char Set(unsigned char v);
};

unsigned char Obj::Set(unsigned char v) {
    m1c = (char)v;
    return 1;
}

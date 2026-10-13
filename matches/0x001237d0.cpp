class Obj {
  public:
    char m[0x15];
    unsigned char Set(unsigned char a);
};

unsigned char Obj::Set(unsigned char a) {
    m[0x15] = a;
    return 1;
}

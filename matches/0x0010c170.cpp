class Obj {
  public:
    char pad[0x14];
    unsigned m14;
    unsigned char Set(unsigned v);
};

unsigned char Obj::Set(unsigned v) {
    m14 = v;
    return 1;
}

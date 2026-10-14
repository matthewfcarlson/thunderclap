class Obj_5d8b0 {
  public:
    char pad[0x24];
    char m24;
    unsigned char Set(unsigned char x);
};

unsigned char Obj_5d8b0::Set(unsigned char x) {
    m24 = x;
    return 1;
}

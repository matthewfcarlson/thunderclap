class Obj_12b1f0 {
  public:
    char pad[0x20];
    char m20;
    unsigned char Set(unsigned char v);
};

unsigned char Obj_12b1f0::Set(unsigned char v) {
    m20 = (char)v;
    return 1;
}

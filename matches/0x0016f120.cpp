class Obj_16f120 {
  public:
    unsigned char Set(unsigned char x);
    char pad[0x24];
    unsigned char m24;
};
unsigned char Obj_16f120::Set(unsigned char x) {
    m24 = x;
    return 1;
}

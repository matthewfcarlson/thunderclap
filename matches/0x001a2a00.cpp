class Obj_1a2a00 {
  public:
    char pad[0x129];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
unsigned char Obj_1a2a00::Set(unsigned char v) {
    value = v;
    return 1;
}
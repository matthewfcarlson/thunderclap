class Obj_17f530 {
  public:
    char pad[0x10];
    unsigned char value;
    unsigned char Set(unsigned char x);
};

unsigned char Obj_17f530::Set(unsigned char x) {
    value = x;
    return 1;
}

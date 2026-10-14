class Obj_d4850 {
  public:
    char pad[0x80c];
    unsigned char field;
    unsigned char Set(unsigned char x);
};

unsigned char Obj_d4850::Set(unsigned char x) {
    field = x;
    return x;
}

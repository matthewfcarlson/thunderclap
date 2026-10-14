class Obj_604a0 {
  public:
    char Pad[0x51];
    unsigned char Value;
    unsigned char Set(unsigned char x);
};

unsigned char Obj_604a0::Set(unsigned char x) {
    Value = x;
    return 1;
}

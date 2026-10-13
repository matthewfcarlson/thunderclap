class Obj {
  public:
    char Pad[0x51];
    unsigned char Value;
    unsigned char Set(unsigned char x);
};

unsigned char Obj::Set(unsigned char x) {
    Value = x;
    return 1;
}

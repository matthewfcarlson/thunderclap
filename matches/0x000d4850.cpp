class Obj {
  public:
    char pad[0x80c];
    unsigned char field;
    unsigned char Set(unsigned char x);
};

unsigned char Obj::Set(unsigned char x) {
    field = x;
    return x;
}

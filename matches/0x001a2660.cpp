class Obj {
  public:
    char pad[0xb8];
    unsigned char field;
    char Set(unsigned char v);
};

char Obj::Set(unsigned char v) {
    field = v;
    return 1;
}

class Obj {
  public:
    char pad[0x77];
    char flag;
    unsigned char Set(unsigned char v);
};

unsigned char Obj::Set(unsigned char v) {
    flag = v;
    return 1;
}

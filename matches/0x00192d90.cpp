class Obj {
  public:
    char pad[0xfd];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
unsigned char Obj::Set(unsigned char v) {
    value = v;
    return 1;
}
class Obj {
  public:
    char pad[0xc];
    unsigned char value;
    char Set(unsigned char v);
};
char Obj::Set(unsigned char v) {
    value = v;
    return 1;
}

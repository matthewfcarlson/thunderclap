class Obj {
  public:
    char pad[0x10];
    char m;
    unsigned char Set(unsigned char x);
};
unsigned char Obj::Set(unsigned char x) {
    m = x;
    return 1;
}

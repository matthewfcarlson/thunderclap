class Obj {
  public:
    char pad[0x10];
    unsigned char m10;
    char Set(unsigned char b);
};
char Obj::Set(unsigned char b) {
    m10 = b;
    return 1;
}

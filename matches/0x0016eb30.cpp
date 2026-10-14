class Obj {
  public:
    char pad[0x21];
    unsigned char value;
    unsigned char Set(unsigned char c);
};
unsigned char Obj::Set(unsigned char c) {
    value = c;
    return 1;
}
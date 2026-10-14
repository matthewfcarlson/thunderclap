class Obj {
  public:
    char pad[0x15];
    char m15;
    unsigned char Set(unsigned char value);
};

unsigned char Obj::Set(unsigned char value) {
    m15 = value;
    return 1;
}

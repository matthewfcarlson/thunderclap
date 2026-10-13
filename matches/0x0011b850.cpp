class Obj {
  public:
    char pad[0x18];
    char m18;
    char Set(unsigned char value);
};

char Obj::Set(unsigned char value) {
    m18 = value;
    return 1;
}

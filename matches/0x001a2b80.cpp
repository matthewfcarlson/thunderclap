class Obj {
  public:
    char Set(unsigned char value);
    char pad[0x159];
    char m159;
};

char Obj::Set(unsigned char value) {
    m159 = value;
    return 1;
}

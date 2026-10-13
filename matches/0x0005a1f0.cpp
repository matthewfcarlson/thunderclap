class Obj {
  public:
    char pad[0x5c];
    char m5c;
    char Set(unsigned char x);
};

char Obj::Set(unsigned char x) {
    m5c = x;
    return 1;
}
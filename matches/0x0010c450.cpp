class Obj {
  public:
    char Pad[0x14];
    char m14;
    char Set(char x);
};

char Obj::Set(char x) {
    m14 = x;
    return 1;
}

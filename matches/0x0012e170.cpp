class Obj {
  public:
    char Set(char c);
    char pad[0x24];
    char m24;
};

char Obj::Set(char c) {
    m24 = c;
    return 1;
}

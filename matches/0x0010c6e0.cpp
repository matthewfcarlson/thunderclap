class Obj {
  public:
    char pad[0x21];
    char m21;
    char Set(char c);
};

char Obj::Set(char c) {
    m21 = c;
    return 1;
}

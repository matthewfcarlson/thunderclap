class Obj {
  public:
    char pad[0x34];
    char m34;
    char Set(char c);
};

char Obj::Set(char c) {
    m34 = c;
    return 1;
}
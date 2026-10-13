class Obj {
  public:
    char pad[0x34];
    char m34;
    char Set(char b);
};

char Obj::Set(char b) {
    m34 = b;
    return 1;
}
class Obj {
  public:
    char pad[0x79];
    char m79;
    char Set(char c);
};

char Obj::Set(char c) {
    m79 = c;
    return 1;
}

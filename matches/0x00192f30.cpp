class Obj {
  public:
    char m[0x12c];
    char Set(char c);
};

char Obj::Set(char c) {
    m[0x12c] = c;
    return 1;
}

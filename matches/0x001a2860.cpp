class Obj {
  public:
    char Set(char x);
    char pad[0xf8];
};

char Obj::Set(char x) {
    pad[0xf8] = x;
    return 1;
}

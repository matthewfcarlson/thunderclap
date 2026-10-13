class Obj {
  public:
    char pad[0x20];
    char m20;
    char Set(char x);
};

char Obj::Set(char x) {
    m20 = x;
    return 1;
}

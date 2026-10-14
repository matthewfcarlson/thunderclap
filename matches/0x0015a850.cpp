class Obj {
  public:
    char pad[0x1c];
    char m1c;
    char m1d;
    char Set(char c);
};
char Obj::Set(char c) {
    m1c = c;
    return 1;
}

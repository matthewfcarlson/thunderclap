class Obj {
  public:
    char pad[0x108];
    char flag;
    char SetFlag(char b);
};
char Obj::SetFlag(char b) {
    flag = b;
    return 1;
}
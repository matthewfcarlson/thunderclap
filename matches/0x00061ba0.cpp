class Obj {
  public:
    char pad[0x24];
    char mFlag;
    char SetFlag(char v);
};

char Obj::SetFlag(char v) {
    mFlag = v;
    return 1;
}
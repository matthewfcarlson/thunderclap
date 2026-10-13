class Obj {
  public:
    char pad[0x2c];
    char mFlag;
    char SetFlag(char value);
};

char Obj::SetFlag(char value) {
    mFlag = value;
    return 1;
}

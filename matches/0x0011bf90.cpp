class Obj_11bf90 {
  public:
    char pad[0x2c];
    char mFlag;
    char SetFlag(char value);
};

char Obj_11bf90::SetFlag(char value) {
    mFlag = value;
    return 1;
}

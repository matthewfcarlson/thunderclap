class Obj_61ba0 {
  public:
    char pad[0x24];
    char mFlag;
    char SetFlag(char v);
};

char Obj_61ba0::SetFlag(char v) {
    mFlag = v;
    return 1;
}
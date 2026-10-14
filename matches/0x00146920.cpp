class Obj_146920 {
  public:
    char pad[12];
    char mFlag;
    bool SetFlag(char value);
};

bool Obj_146920::SetFlag(char value) {
    mFlag = value;
    return true;
}

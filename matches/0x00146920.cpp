class Obj {
  public:
    char pad[12];
    char mFlag;
    bool SetFlag(char value);
};

bool Obj::SetFlag(char value) {
    mFlag = value;
    return true;
}

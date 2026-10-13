class Obj {
  public:
    char pad[0xc];
    int mFlag;
    bool SetFlag(int value);
};

bool Obj::SetFlag(int value) {
    mFlag = value;
    return true;
}

class Obj_14caa0 {
  public:
    char pad[0xc];
    int mFlag;
    bool SetFlag(int value);
};

bool Obj_14caa0::SetFlag(int value) {
    mFlag = value;
    return true;
}

class Obj_11b930 {
  public:
    char pad[0x1f];
    char mFlag;
    bool Set(bool x);
};

bool Obj_11b930::Set(bool x) {
    mFlag = x;
    return true;
}

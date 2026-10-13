class Obj {
  public:
    char pad[0x1f];
    char mFlag;
    bool Set(bool x);
};

bool Obj::Set(bool x) {
    mFlag = x;
    return true;
}

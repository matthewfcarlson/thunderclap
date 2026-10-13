class Obj {
  public:
    char mFlag;
    char mPad[8];
    int mValue;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mValue = v;
    return true;
}

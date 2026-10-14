class Obj_14c6b0 {
  public:
    char mFlag;
    char mPad[8];
    int mValue;
    bool Set(int v);
};

bool Obj_14c6b0::Set(int v) {
    mValue = v;
    return true;
}

class Obj {
  public:
    char Fn(int v);
    char mPad[12];
    int mVal;
};

char Obj::Fn(int v) {
    mVal = v;
    return 1;
}